# New ports collection makefile for:	ntp
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	ntp
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

LATEST_LINK=	${PORTNAME}
# ntp's configure script created by autoconf 2.14.1 doesn't work
# if GNU_CONFIGURE is defined
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

.if defined(ENABLE_RAWDCF)
CONFIGURE_ARGS+=	--enable-RAWDCF
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ntp
	${TAR} -C ${WRKSRC}/html -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/ntp --unlink -xf -
	${FIND} ${PREFIX}/share/doc/ntp | \
		${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/share/doc/ntp -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
