# New ports collection makefile for:	smbfs
# Date created:				2th Dec 2000
# Whom:					Jaedoc Lee <tokky@fdns.org>
#
# $FreeBSD$
#

PORTNAME=	smbfs
PORTVERSION=	1.3.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.butya.kz/pub/smbfs/

MAINTAINER=	tokky@fdns.org

.if defined(WITH_ICONV)
pre-fetch:
	@${ECHO}
	@${ECHO} "Using iconv library"
	@${ECHO}

LIB_DEPENDS= iconv.2:${PORTSDIR}/converters/iconv

post-configure:
	@${SED} -e 's/# USE_ICONV=yes/USE_ICONV=yes/g' < ${WRKSRC}/config.mk.in > ${WRKSRC}/config.mk
.else
pre-fetch:
	@${ECHO}
	@${ECHO} "Not Using iconv library"
	@${ECHO}
	@${ECHO} "You may set iconv library (make WITH_ICONV=yes)"
	@${ECHO} "to compile smbfs with the supplied iconv."
	@${ECHO}

post-configure:
	@${CP} ${WRKSRC}/config.mk.in ${WRKSRC}/config.mk
.endif

post-install:
	cd ${WRKSRC} && make makedev
	@${INSTALL_DATA} ${WRKSRC}/examples/dot.nsmbrc ${LOCALBASE}/etc/nsmb.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/smbfs.sh.sample ${LOCALBASE}/etc/rc.d/smbfs.sh.sample

.include <bsd.port.mk>
