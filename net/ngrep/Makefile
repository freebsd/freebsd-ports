# ex:ts=8
# Ports collection makefile for:  ngrep
# Date created:			  Sat Jan 01, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ngrep
PORTVERSION=	1.40.1
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Network grep

WRKSRC=		${WRKDIR}/ngrep
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre --with-restart
ALL_TARGET=	ngrep
MAN8=		ngrep.8

PORTDOCS=	BUGS CHANGES README README.pcre USAGE

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
EXTRA_PATCHES=	${PATCHDIR}/patch5-configure ${PATCHDIR}/patch5-ngrep
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
