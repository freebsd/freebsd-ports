# $FreeBSD$

PORTNAME=	hpijs
PORTVERSION=	2.1.4
PORTREVISION=	11
CATEGORIES=	print
MASTER_SITES=	SF/hpinkjet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drivers and support resources for HP Inkjet Printers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	hplip-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cups-install
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		jpeg shebangfix
SHEBANG_FILES=	foomatic-rip

OPTIONS_DEFINE=	CUPS DOCS
OPTIONS_DEFAULT=CUPS
OPTIONS_SUB=	yes

CUPS_RUN_DEPENDS=	foomatic-rip:print/cups-filters
CUPS_USES_OFF=		ghostscript:run perl5

post-patch:
	@${REINPLACE_CMD} '/^docdir =/s|=.*|= ${DOCSDIR}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
