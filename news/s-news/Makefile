PORTNAME=	s-news
PORTVERSION=	0.1.11
PORTREVISION=	6
CATEGORIES=	news
MASTER_SITES=	http://www.lost.org.uk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple news server for hosts with one or two users
WWW=		https://www.lost.org.uk/snews.html

LIB_DEPENDS=	libgdbm.so:databases/gdbm

CONFLICTS=	cnews nntp trn4 # bin/inews sbin/nntpd

CONFIGURE_ARGS+= \
		--with-confdir=${PREFIX}/etc/s-news \
		--with-spooldir=/var/spool/s-news
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

USES=		gmake fakeroot
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	README README.conf README.suck TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
