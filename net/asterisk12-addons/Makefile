# New ports collection makefile for:	asterisk-addons
# Date created:				23 March 2006
# Whom:					Fabian Gast <fgast@only640k.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk-addons
PORTVERSION=	1.2.3
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	12

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional modules for the Asterisk Open Source PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

BROKEN=		does not build
ONLY_FOR_ARCHS=	i386
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
