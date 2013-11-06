# Created by: Lars Erik Gullerud <lerik@nolink.net>
# $FreeBSD$

PORTNAME=	ripe-whois
PORTVERSION=	3.2.2
CATEGORIES=	net ipv6
MASTER_SITES=	SF/whois/whois/${PORTVERSION}
DISTNAME=	whois3-${PORTVERSION}

MAINTAINER=	lerik@nolink.net
COMMENT=	The RIPE whois client version 3

USES=		perl5
USE_PERL5=	build

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/whois3 man/man1/whois3.1.gz

post-patch::
	${REINPLACE_CMD} -E \
		-e '/^bin_PROGRAMS =/ s/whois\$$\(EXEEXT\)/whois3$$(EXEEXT)/' \
		${WRKSRC}/Makefile.in

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
