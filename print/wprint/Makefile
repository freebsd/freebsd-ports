# Created by: ijliao
# $FreeBSD$

PORTNAME=	wprint
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://programoj.esperanto.org.uy/angle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mozilla/HtmlDoc/Netscape Postscript Filter

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USES=		iconv perl5
GNU_CONFIGURE=	yes

MAN1=		wprint.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
.for file in man/wprint.1.pod src/wprint.c
	@${REINPLACE_CMD} -e "s|/etc/wprint\.conf|${PREFIX}/etc/wprint.conf|g" \
		${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's,$$(srcdir)/wprint.conf $$(sysconfdir),$$(srcdir)/wprint.conf $$(sysconfdir)/wprint.conf.dist,g' \
		${WRKSRC}/etc/Makefile.in

post-install:
	@if [ ! -f ${PREFIX}/etc/wprint.conf ]; then \
	  ${CP} -p ${PREFIX}/etc/wprint.conf.dist ${PREFIX}/etc/wprint.conf ; \
	fi

.include <bsd.port.mk>
