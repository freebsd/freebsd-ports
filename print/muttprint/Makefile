# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME?=	muttprint
PORTVERSION=	0.72d
PORTREVISION=	10
CATEGORIES?=	print mail
MASTER_SITES=	SF/muttprint/muttprint/muttprint-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Utility to print mail for most any mail client

RUN_DEPENDS=	psnup:${PORTSDIR}/print/psutils \
		uncompface:${PORTSDIR}/mail/faces \
		convert:${PORTSDIR}/graphics/ImageMagick \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv

USES=		perl5 gmake
USE_TEX=	texmf

NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

OPTIONS_DEFINE=	CUPS DOCS
CUPS_RUN_DEPENDS=	cupstestppd:${PORTSDIR}/print/cups-base \
			espgs:${PORTSDIR}/print/cups-pstoraster

.if !defined(PAPERSIZE)
PAPERSIZE=	letter
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
PRINT_COMMAND=CUPS
.else
PRINT_COMMAND=lpr -P$$PRINTER
.endif

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=install-with-doc
.endif

pre-everything::
	@${ECHO}
	@${ECHO} Set PAPERSIZE=a4 if you need that paper size.
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
	@${GZIP_CMD} ${WRKSRC}/doc/manpages/*/muttprint.1

.include <bsd.port.mk>
