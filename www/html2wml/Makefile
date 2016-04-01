# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	html2wml
PORTVERSION=	0.4.11
CATEGORIES=	www
MASTER_SITES=	SF/htmlwml/Html2Wml/${PORTVERSION} \
		http://maddingue.free.fr/softwares/download/Html2Wml/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CGI that can do on-the-fly HTML to WML conversion

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Text-Template>0:textproc/p5-Text-Template \
		p5-XML-Parser>0:textproc/p5-XML-Parser \
		p5-libwww>0:www/p5-libwww

USES=		perl5 shebangfix
SHEBANG_FILES=	html2wml.cgi
NO_ARCH=	yes

PORTDOCS=	*
PLIST_FILES=	bin/html2wml man/man1/html2wml.1.gz

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC}/doc; \
	${LN} -sf readme.pod html2wml.pod; \
	pod2man --center="Html2Wml Documentation" \
		--release=0.4.0 html2wml.pod > html2wml.man

checkconfig:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} default

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2wml.cgi \
		${STAGEDIR}${PREFIX}/bin/html2wml
	${INSTALL_MAN} ${WRKSRC}/doc/html2wml.man \
		${STAGEDIR}${MANPREFIX}/man/man1/html2wml.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in INSTALL NEWS NOTES README TODO ChangeLog \
	doc/readme.html doc/readme.pdf doc/readme.pod doc/readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/t
	${INSTALL_DATA} ${WRKSRC}/t/form.html ${STAGEDIR}${DOCSDIR}/t
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/t/samples
.for D in inc_para.wml inc_prev.wml mix1.html mix2.html struct.html \
	t-a.html t-anchor.html t-br.html t-double-tags.html t-extcharset.html \
	t-frames.html t-img.html t-include.html t-nest.html t-no-tag.html \
	t-special-chars.html t-urls.html
	${INSTALL_DATA} ${WRKSRC}/t/samples/${D} ${STAGEDIR}${DOCSDIR}/t/samples
.endfor

.include <bsd.port.mk>
