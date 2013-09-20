# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	pchar
PORTVERSION=	1.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.kitchenlab.org/www/bmah/Software/pchar/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bmah

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sandia Internet path characterization tool

GNU_CONFIGURE=	yes
MAN8=		pchar.8

CONFIGURE_ARGS= --with-pcap
CONFIGURE_ENV+=	ac_cv_sizeof_bool=1

PLIST_FILES=	sbin/pchar

PORTDOCS=	README CHANGES FAQ

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
