# ex:ts=8
# Ports collection makefile for:  ngrep
# Date created:			  Sat Jan 01, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ngrep
PORTVERSION=	1.42
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Network grep

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre \
		--disable-pcap-restart \
		--enable-dropprivs-onlyroot
ALL_TARGET=	ngrep
USE_BZIP2=	yes

MAN8=		ngrep.8
PLIST_FILES=	bin/ngrep

PORTDOCS=	BUGS CHANGES CREDITS INSTALL LICENSE README README.pcre TODO

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
