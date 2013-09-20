# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	mopd
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		VAX-netboot-HOWTO VS3100-console-cmds.txt
.endif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	MOP Loader Daemon for netbooting DEC machines

NO_STAGE=	yes
.include <bsd.port.pre.mk>

MAKE_ENV=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man NO_MANCOMPRESS=true
MAN1=		mopprobe.1 moptrace.1 mopchk.1 mopa.out.1
MAN8=		mopd.8

do-configure:
	@${REINPLACE_CMD} -e 's/MAN=/MAN8=/' ${WRKSRC}/mopd/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${DISTDIR}/VAX-netboot-HOWTO  \
		${DISTDIR}/VS3100-console-cmds.txt  ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
