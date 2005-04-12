# ex:ts=8
# Ports collection makefile for:	xmlsec
# Date created:			Jul 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlsec
PORTVERSION=	0.0.15
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	XML Security Library

RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_OPENSSL=	yes
USE_GNOME=	gnomehack libxslt
USE_INC_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=	xmlsec.1 xmlsec-config.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
