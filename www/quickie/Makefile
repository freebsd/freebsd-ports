# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	quickie
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF \
		http://quickie.sourceforge.net/:pdf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small footprint, fast Wiki engine written in C++

LICENSE=	GPLv2+

USES=		alias perl5
USE_PERL5=	build patch
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--localstatedir=${DATADIR}
MAKE_ENV=	RPM_BUILD_ROOT="${STAGEDIR}"

SUB_FILES=	pkg-message

PORTDOCS=	${DISTNAME}.pdf

OPTIONS_DEFINE=		CGI DOCS
OPTIONS_SUB=		yes

CGI_DESC=		Install CGI binary
DOCS_DISTFILES=		${DISTNAME}.pdf:pdf

.include <bsd.port.options.mk>

post-patch:
	@${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/lib
	@${REINPLACE_CMD} -e 's|output_html_quote::name()|name()|' \
		${WRKSRC}/lib/output/html_quote.h
	@${REINPLACE_CMD} -e 's|input_uudecode::read_inner|read_inner|' \
		${WRKSRC}/lib/input/uudecode.h
# Fix -jX builds: tell compiler to generate files in the right place
	@${PERL} -0pi -e 's/(\$$\(CXX\).*?\s+-c\s+.*?) \
		\s+mv\s+\S+/$$1 -o/sgx' ${WRKSRC}/Makefile.in

pre-install:
.for i in admin manual
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
.endfor

post-install:
.if ${PORT_OPTIONS:MCGI}
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${LN} -sf ${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/www/cgi-bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${DISTDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
