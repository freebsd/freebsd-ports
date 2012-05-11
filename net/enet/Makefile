# New ports collection makefile for:	enet
# Date created:		2006-09-23
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enet
PORTVERSION=	1.3.3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and robust communication library based on UDP

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf:env
USE_LDCONFIG=	yes

DOCS=		design.txt docs/FAQ.dox docs/design.dox docs/tutorial.dox


AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|1.11.1|%%AUTOMAKE_APIVER%%|g' \
			  -e 's|2.67|%%AUTOCONF_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
