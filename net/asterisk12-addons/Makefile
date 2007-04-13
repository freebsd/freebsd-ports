# New ports collection makefile for:	asterisk-addons
# Date created:				23 March 2006
# Whom:					Fabian Gast <fgast@only640k.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk-addons
PORTVERSION=	1.2.3
PORTREVISION=   1
PKGNAMESUFFIX=	12
CATEGORIES=	net
MASTER_SITES=	http://ftp.digium.com/pub/asterisk/ \
		http://ftp.digium.com/pub/asterisk/old-releases/ \
		ftp://ftp.asterisk.org/pub/telephony/asterisk/ \
		ftp://ftp.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	fgast@only640k.org
COMMENT=	Additional modules for the Asterisk Open Source PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

ONLY_FOR_ARCHS=	i386 sparc64 amd64
USE_MYSQL=	yes
USE_GMAKE=	yes

CONF_SAMPLES=	cdr_mysql.conf.sample res_mysql.conf.sample
ASTETCDIR=	${PREFIX}/etc/asterisk

post-patch:
	@${REINPLACE_CMD} 's,^CFLAGS+=-I../asterisk,CFLAGS+=-I${LOCALBASE}/include,' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${ASTETCDIR}
.for f in ${CONF_SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/configs/$f ${ASTETCDIR}
.endfor

.include <bsd.port.mk>
