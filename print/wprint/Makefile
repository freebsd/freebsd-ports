# ex:ts=8
# Ports collection makefile for:	wprint
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wprint
PORTVERSION=	2.05
CATEGORIES=	print
MASTER_SITES=	http://www.esperanto.org.uy/programoj/angle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mozilla/HtmlDoc/Netscape Postscript Filter

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		freetype:${PORTSDIR}/print/freetype2

USE_REINPLACE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	wprint.1

post-patch:
.for file in man/wprint.1.pod src/wprint.c
	@${REINPLACE_CMD} -e "s|/etc/wprint\.conf|${PREFIX}/etc/wprint.conf|g" \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
