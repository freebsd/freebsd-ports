# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s-news
PORTVERSION=	0.1.11
PORTREVISION=	3
CATEGORIES=	news
MASTER_SITES=	http://www.lost.org.uk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple news server for hosts with one or two users

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm

CONFLICTS=	leafnode-[1-9]* nntp-[0-9]*

CONFIGURE_ARGS+= \
		--with-confdir=${PREFIX}/etc/s-news \
		--with-spooldir=/var/spool/s-news
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

USES=	gmake
GNU_CONFIGURE=	yes

MAN1=		inews.1
MAN8=		expire.8 listactive.8 makehistory.8 newgroup.8 nntpd.8 overview.8 \
		qnews.8 rmgroup.8 rnews.8

PORTDOCS=	README README.conf README.suck TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
