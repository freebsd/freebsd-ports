# ex:ts=8
# Ports collection makefile for:	ulxmlrpcpp
# Date created:			Dec 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ulxmlrpcpp
PORTVERSION=	1.2.5
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E:S/b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ultra lightweight xml-rpc library written in C++

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-doxygen --disable-latex-docs
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
