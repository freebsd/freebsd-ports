# New ports collection makefile for:	smbfs
# Date created:				2th Dec 2000
# Whom:					Jaedoc Lee <tokky@fdns.org>
#
# $FreeBSD$
#

PORTNAME=	smbfs
PORTVERSION=	1.3.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.butya.kz/pub/smbfs/

MAINTAINER=	bp@freebsd.org

NO_PACKAGE=     "Depends on kernel"

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=configure

PLIST_SUB=	KMODDIR=${KMODDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"OS versions prior to 400000 is not supported"
.endif

.if defined(WITH_ICONV)
LIB_DEPENDS= iconv.2:${PORTSDIR}/converters/iconv
CONFIGURE_ARGS+= -DWITH_ICONV
.endif

.if defined(SMP_SUPPORT)
CONFIGURE_ARGS+= -DSMP_SUPPORT
.endif

pre-fetch:
.if !defined(WITH_ICONV)
	@${ECHO_MSG} "NOTE: To enable support for various charsets "
	@${ECHO_MSG} "add \"WITH_ICONV=yes\" to argument of make."
.endif
.if !defined(SMP_SUPPORT)
	@${ECHO_MSG} "NOTE: SMP suppport can be enabled by adding "
	@${ECHO_MSG} "\"SMP_SUPPORT=yes\" to argument of make."
.endif

post-install:
	cd ${WRKSRC} && make makedev
	@${INSTALL_DATA} ${WRKSRC}/examples/dot.nsmbrc ${LOCALBASE}/etc/nsmb.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/smbfs.sh.sample ${LOCALBASE}/etc/rc.d/smbfs.sh.sample

.include <bsd.port.post.mk>
