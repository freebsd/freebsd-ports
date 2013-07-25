# New ports collection makefile for:	archiveopteryx
# Date created:		2010-09-15
# Whom:			Ashish SHUKLA <ashish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	archiveopteryx
PORTVERSION=	3.1.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://archiveopteryx.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	download

MAINTAINER=	feld@freebsd.org
COMMENT=	An advanced PostgreSQL-based IMAP/POP server

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/bsd.txt

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

USE_BZIP2=	yes
USE_PERL5_BUILD=	yes

MAKE_JOBS_SAFE=	yes

MAN5=	aoxsuper.conf.5 archiveopteryx.conf.5
MAN8=	aox.8 aoximport.8 archiveopteryx.8 deliver.8 installer.8 logd.8 \
	recorder.8 tlsproxy.8

PORTDOCS=	COPYING README bsd.txt

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

USERS=		aox
GROUPS=		aox

JAM?=		${LOCALBASE}/bin/jam

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'

do-build:
	@cd ${WRKSRC} && ${JAM} -j${MAKE_JOBS_NUMBER}

do-install:
	@cd ${WRKSRC} && ${JAM} install

post-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
