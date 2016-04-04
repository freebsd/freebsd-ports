# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	muttprint
PORTVERSION=	0.73
PORTREVISION=	1
CATEGORIES=	print mail
MASTER_SITES=	SF/muttprint/muttprint/muttprint-${PORTVERSION}

MAINTAINER=	guru@unixarea.de
COMMENT=	Utility to print mail for most any mail client

LICENSE=	GPLv2

BUILD_DEPENDS=	docbook2pdf:textproc/docbook-utils \
		docbook-sgml>0:textproc/docbook-sgml
RUN_DEPENDS=	psnup:print/psutils \
		uncompface:mail/faces \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Text-Iconv>=0:converters/p5-Text-Iconv

GNU_CONFIGURE=	yes
USES=		autoreconf gmake perl5
USE_TEX=	latex dvipsk

NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

OPTIONS_DEFINE=		CUPS X11
OPTIONS_DEFAULT=	X11
X11_DESC=		graphics/ImageMagick[-nox11] dependency

CUPS_RUN_DEPENDS=	lpr-cups:print/cups

.if !defined(PAPERSIZE)
PAPERSIZE=	letter
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
PRINT_COMMAND=CUPS
.else
PRINT_COMMAND=lpr -P$$PRINTER
.endif

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:graphics/ImageMagick-nox11
.endif

pre-everything::
	@${ECHO}
	@${ECHO} Set PAPERSIZE=a4 if you need that paper size.
	@${ECHO}

post-patch:
	@${RM} -f ${WRKSRC}/pics/*.orig
.if ${PAPERSIZE}==a4
	@${REINPLACE_CMD} 's|%%PAPERSIZE%%|${PAPERSIZE:tu}|' \
		${WRKSRC}/muttprint
.else
	@${REINPLACE_CMD} 's|%%PAPERSIZE%%|${PAPERSIZE}|' \
		${WRKSRC}/muttprint
.endif
	@${REINPLACE_CMD} 's|%%PRINT_COMMAND%%|${PRINT_COMMAND}| ; \
		s|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/muttprint
.if ${PORT_OPTIONS:MCUPS}
	@${REINPLACE_CMD} 's|lpr $$CUPS_OPTIONS|${PREFIX}/bin/lpr $$CUPS_OPTIONS|' ${WRKSRC}/muttprint
.endif

.include <bsd.port.mk>
