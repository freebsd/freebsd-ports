# ex:ts=8
# Ports collection makefile for:	hydra
# Date created:			Apr 2, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	0.1.7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.hellug.gr/pub/software/hydra/ \
		http://hydra.hellug.gr/download/ \
		ftp://ftp.planetmirror.com/pub/hydra/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high performance multi-threaded web server

LIB_DEPENDS=	gnutls.12:${PORTSDIR}/security/gnutls

NO_LATEST_LINK=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure
.for file in src/defines.h examples/hydra.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${file}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/etc/hydra
.for file in hydra.conf mime.types
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${PREFIX}/etc/hydra/${file}-dist
	[ -f ${PREFIX}/etc/hydra/${file} ] || \
		${INSTALL_DATA} ${WRKSRC}/examples/${file} ${PREFIX}/etc/hydra/
.endfor

.include <bsd.port.mk>
