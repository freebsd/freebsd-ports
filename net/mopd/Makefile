# ex:ts=8
# Ports collection makefile for:  mopd
# Date created:			  Sun Nov 14, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	mopd
PORTVERSION=	2.5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/OS/NetBSD/mopd/  		\
		http://world.std.com/~bdc/projects/vaxen/netboot/	\
		http://world.std.com/~bdc/projects/vaxen/		\
		http://world.std.com/~bdc/projects/vaxen/docs/
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		VAX-netboot-HOWTO VS3100-console-cmds.txt
.endif

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	MOP Loader Daemon for netbooting DEC machines

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
#	MANDIR is concetenated to DESTDIR which all forms the man install dir...

.include <bsd.port.pre.mk>

MAKE_ENV=	DESTDIR=${PREFIX} MANDIR=/man/man NOMANCOMPRESS=true
USE_REINPLACE=	yes
.if ${OSVERSION} >= 502126
USE_GCC=	3.3
.endif
MAN1=		mopprobe.1 moptrace.1 mopchk.1 mopa.out.1
MAN8=		mopd.8

do-configure:
	@${REINPLACE_CMD} -e 's:/usr/sbin:/sbin:' ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's/MAN=/MAN8=/' ${WRKSRC}/mopd/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mopd
	@${INSTALL_MAN} ${DISTDIR}/VAX-netboot-HOWTO  \
		${DISTDIR}/VS3100-console-cmds.txt  ${PREFIX}/share/doc/mopd
.endif

.include <bsd.port.post.mk>
