# New ports collection makefile for:    husky-base
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	0.2.0
CATEGORIES=	news mail
MASTER_SITES=	http://www.physcip.uni-stuttgart.de:8080/fidosoft.husky/
DISTNAME=	huskybse-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org

WRKSRC=		${WRKDIR}/huskybse-${PORTVERSION}
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's^/usr/local^${PREFIX}^' \
		-e 's^CFGDIR=/etc/fido^CFGDIR=${PREFIX}/etc/fido^' \
		-e 's^# INFODIR=/usr/local/info^INFODIR=${PREFIX}/info^' \
		-e 's^#HTMLDIR=$$(PREFIX)/lib/husky^HTMLDIR=${PREFIX}/share/doc/husky^' \
		-e 's^$$(CFGDIR)/msged.cfg^~/.msged^' \
		-e 's^CC=gcc^CC=${CC}^' \
		-e 's^CXX=g++^CXX=${CXX}^' \
		-e 's^MKSHARED=gcc^MKSHARED=${CC}^' \
		-e 's^OPTCFLAGS=^OPTCFLAGS=-c ${CFLAGS}^' \
			${WRKSRC}/huskymak.cfg

pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/etc/fido ${PREFIX}/share/doc/husky
	@${CHOWN} fido:fido ${PREFIX}/etc/fido
	@${INSTALL_DATA} ${WRKSRC}/huskymak.cfg ${PREFIX}/etc/fido

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
