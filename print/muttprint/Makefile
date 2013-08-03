# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME?=	muttprint
PORTVERSION=	0.72d
PORTREVISION=	7
CATEGORIES?=	print mail
MASTER_SITES=	SF/muttprint/muttprint/muttprint-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Utility to print mail for most any mail client

USES=		perl5

.if !defined(PAPERSIZE)
PAPERSIZE=	letter
.endif

RUN_DEPENDS=	psnup:${PORTSDIR}/print/psutils \
		uncompface:${PORTSDIR}/mail/faces \
		convert:${PORTSDIR}/graphics/ImageMagick \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
.if defined(WITH_CUPS)
RUN_DEPENDS+=	cupstestppd:${PORTSDIR}/print/cups-base \
		espgs:${PORTSDIR}/print/cups-pstoraster
.endif

NO_BUILD=	yes
PLIST_SUB+=	LANGINFO="@comment "

REINPLACE_ARGS=	-i ""
USE_TEX=	latex
USE_GMAKE=	yes

MAN1=		muttprint.1
MANCOMPRESSED=	yes

.if defined(WITH_CUPS)
PRINT_COMMAND=CUPS
.else
PRINT_COMMAND=lpr -P$$PRINTER
.endif

.if !defined(NOPORTDOCS)
INSTALL_TARGET=install-with-doc
.endif

pre-everything::
	@${ECHO}
	@${ECHO} Set PAPERSIZE=a4 if you need that paper size.
	@${ECHO} Set WITH_CUPS=yes if you want to use CUPS.
	@${ECHO}

post-patch:
	@${RM} -f ${WRKSRC}/pics/*.orig
	@${GUNZIP_CMD} ${WRKSRC}/doc/manpages/*/muttprint.1.gz
	@${REINPLACE_CMD} -e 's|/usr/share/doc/packages|${PREFIX}/share/doc|g ; \
		s|/usr/share|${PREFIX}/share|g ; \
		s|/usr/bin|${PREFIX}/bin|g ; \
		s|/etc|${PREFIX}/etc|g ; \
		s|/usr/lib|${PREFIX}/lib|g' \
			${WRKSRC}/doc/manpages/*/muttprint.1 \
			${WRKSRC}/doc/manual/*/manual-*/*.html
	@${REINPLACE_CMD} -e '/\.css/d' ${WRKSRC}/doc/manual/*/Makefile
.if ${PAPERSIZE}==a4
	@${REINPLACE_CMD} 's|%%PAPERSIZE%%|${PAPERSIZE:U}|' \
		${WRKSRC}/muttprint
.else
	@${REINPLACE_CMD} 's|%%PAPERSIZE%%|${PAPERSIZE}|' \
		${WRKSRC}/muttprint
.endif
	@${REINPLACE_CMD} 's|%%PRINT_COMMAND%%|${PRINT_COMMAND}| ; \
		s|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/muttprint
.if defined(WITH_CUPS)
	@${REINPLACE_CMD} 's|lpr $$CUPS_OPTIONS|${PREFIX}/bin/lpr $$CUPS_OPTIONS|' ${WRKSRC}/muttprint
.endif
	@${GZIP_CMD} ${WRKSRC}/doc/manpages/*/muttprint.1

.include <bsd.port.mk>
