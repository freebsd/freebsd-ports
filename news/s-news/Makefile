# New ports collection makefile for:	s-news
# Date created:				Jul 13 13:29:47 EEST 2004
# Whom:					Andrey Slusar <vasallia@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	s-news
PORTVERSION=	0.1.11
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.lost.org.uk/

MAINTAINER=	vasallia@ukr.net
COMMENT=	Simple news server for hosts with one or two users

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

CONFLICTS=	nntp-*

NEWSSPOOL=	/var/spool/s-news

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-confdir=${PREFIX}/etc/s-news \
		--with-spooldir=${NEWSSPOOL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

MAN1=		inews.1
MAN8=		expire.8 listactive.8 makehistory.8 newgroup.8 nntpd.8 overview.8 \
		qnews.8 rmgroup.8 rnews.8

PORTDOCS=	README README.conf README.suck TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
