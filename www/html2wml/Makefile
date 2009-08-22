# New ports collection makefile for:   html2wml
# Date created:        15 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	html2wml
PORTVERSION=	0.4.11
CATEGORIES=	www
MASTER_SITES=	SF/htmlwml/Html2Wml/${PORTVERSION} http://maddingue.free.fr/softwares/download/Html2Wml/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CGI that can do on-the-fly HTML to WML conversion

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_PERL5=	yes
MAKE_ARGS=	PREFIX=${PREFIX} DOCDIR=${DOCDIR}

PLIST_FILES=	bin/html2wml
MAN1=		html2wml.1
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-build:
	cd ${BUILD_WRKSRC}/doc; \
	${LN} -sf readme.pod html2wml.pod; \
	pod2man --center="Html2Wml Documentation" \
		--release=0.4.0 html2wml.pod > html2wml.man

checkconfig:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} default

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/html2wml/t/samples
.for D in INSTALL NEWS NOTES README TODO ChangeLog
	${INSTALL_DATA} ${WRKSRC}/$D ${PREFIX}/share/doc/html2wml
.endfor
.for D in html pdf pod txt
	${INSTALL_DATA} ${WRKSRC}/doc/readme.$D ${PREFIX}/share/doc/html2wml
.endfor
	${INSTALL_DATA} ${WRKSRC}/t/form.html \
		${PREFIX}/share/doc/html2wml/t
.for D in inc_para.wml inc_prev.wml mix1.html mix2.html struct.html \
	t-a.html t-anchor.html t-br.html t-double-tags.html t-extcharset.html \
	t-frames.html t-img.html t-include.html t-nest.html t-no-tag.html \
	t-special-chars.html t-urls.html
	${INSTALL_DATA} ${WRKSRC}/t/samples/$D \
		${PREFIX}/share/doc/html2wml/t/samples
.endfor
.endif

.include <bsd.port.mk>
