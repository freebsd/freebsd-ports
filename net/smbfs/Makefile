# New ports collection makefile for:	smbfs
# Date created:				2th Dec 2000
# Whom:					Jaedoc Lee <tokky@fdns.org>
#
# $FreeBSD$
#

PORTNAME=	smbfs
PORTVERSION=	1.4.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.butya.kz/pub/smbfs/

MAINTAINER=	bp@freebsd.org
COMMENT=	SMB/CIFS protocol and SMB/CIFS file system implementation

NO_PACKAGE=     "Depends on kernel"

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=configure


.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"OS versions prior to 400000 is not supported"
.endif

.if ${OSVERSION} > 440002 && ${OSVERSION} < 500000
IGNORE=		"OS versions subsequent to 440002 include smbfs"
.endif

.if ${OSVERSION} < 500000
PLIST_SUB=	KMODDIR=${KMODDIR}
.else
PLIST_SUB=	KMODDIR="@comment "
.endif

.if ${OSVERSION} > 500027
IGNORE=		"OS versions subsequent to 500027 include smbfs"
.endif

.if defined(SMP_SUPPORT)
CONFIGURE_ARGS+= -DSMP_SUPPORT
.endif

pre-fetch:
.if !defined(SMP_SUPPORT) && ${OSVERSION} < 500000
	@${ECHO_MSG} "NOTE: SMP support can be enabled by adding "
	@${ECHO_MSG} "\"SMP_SUPPORT=yes\" to argument of make."
.endif

post-install:
	cd ${WRKSRC} && make makedev
	@${INSTALL_DATA} ${WRKSRC}/examples/dot.nsmbrc ${LOCALBASE}/etc/nsmb.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/smbfs.sh.sample ${LOCALBASE}/etc/rc.d/smbfs.sh.sample

.include <bsd.port.post.mk>
