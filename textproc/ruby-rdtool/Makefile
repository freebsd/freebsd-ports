# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rdtool
PORTVERSION=	0.6.38
CATEGORIES=	textproc ruby
MASTER_SITES=	https://github.com/uwabami/${PORTNAME}/tarball/v${PORTVERSION}/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	uwabami-${PORTNAME}-v${PORTVERSION}-0-g${GITVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	RD to HTML/man/etc. converter (RD is to Ruby as POD is to Perl)

BUILD_DEPENDS=	racc:${PORTSDIR}/devel/rubygem-racc

GITVERSION=	c895345
WRKSRC=		${WRKDIR}/uwabami-${PORTNAME}-${GITVERSION}

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RAKE=	yes

RUBY_MODNAME=	rd

DOCS_EN=	README.rd	doc/rd-draft.rd
DOCS_JA=	README.rd.ja	doc/rd-draft.rd.ja

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/rd
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc ${STAGEDIR}${RUBY_SITELIBDIR}/rd/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/rd/dot.rd2rc ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
