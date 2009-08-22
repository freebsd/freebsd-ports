# New ports collection makefile for:	ripe-whois
# Date created:		18th February 2004
# Whom:			Lars Erik Gullerud <lerik@nolink.net>
#
# $FreeBSD$
#

PORTNAME=	ripe-whois
PORTVERSION=	3.2.2
CATEGORIES=	net ipv6
MASTER_SITES=	SF/whois/whois/${PORTVERSION}
DISTNAME=	whois3-${PORTVERSION}

MAINTAINER=	lerik@nolink.net
COMMENT=	The RIPE whois client version 3

USE_PERL5_BUILD=	yes

GNU_CONFIGURE=	yes

MAN1=		whois3.1
PLIST_FILES=	bin/whois3

post-patch::
	${REINPLACE_CMD} -E \
		-e '/^bin_PROGRAMS =/ s/whois\$$\(EXEEXT\)/whois3$$(EXEEXT)/' \
		${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
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
