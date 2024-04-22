PORTNAME=	ripe-whois
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/whois/whois/${PORTVERSION}
DISTNAME=	whois3-${PORTVERSION}

MAINTAINER=	lerik@nolink.net
COMMENT=	The RIPE whois client version 3
WWW=		http://whois.sf.net

USES=		perl5 gmake
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/whois3 share/man/man1/whois3.1.gz

post-patch::
	${REINPLACE_CMD} -E \
		-e '/^bin_PROGRAMS =/ s/whois\$$\(EXEEXT\)/whois3$$(EXEEXT)/' \
		${WRKSRC}/Makefile.in

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/doc
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
PORTDOCS=	HELP.txt FLAGS.txt
.else
post-patch::
	${REINPLACE_CMD} -E \
		-e '/^install-data-am:/ s/install-whoisdataDATA//' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
