# New ports collection makefile for:	radmind
# Date created:		2003-11-17
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	radmind
PORTVERSION=	1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://rsug.itd.umich.edu/software/radmind/files/
#DISTNAME=		radmind-1.3.0-rc2
EXTRACT_SUFX=	.tgz

MAINTAINER=	paul@aps.org
COMMENT=	Utility for administering filesystem changes

USE_OPENSSL=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		fsdiff.1 ktcheck.1 lapply.1 lcksum.1 lcreate.1 lfdiff.1 \
		lmerge.1 twhich.1
MAN5=		applefile.5
MAN8=		radmind.8
DOCS=		COPYRIGHT README SPEC

post-install:
	# Ugly hack to remove generated man pages
	${RM} -rf ${WRKSRC}/tmp
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
