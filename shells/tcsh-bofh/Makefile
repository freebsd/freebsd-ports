# New ports collection makefile for:	tcsh-bofh
# Date created:		2005-10-13
# Whom:			Krzysztof Kowalewski <pyzmen@kam.pl>
#
# $FreeBSD$
#

PORTNAME=	tcsh-bofh
PORTVERSION=	6.12.00
CATEGORIES=	shells security
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/old/ \
		ftp://ftp.gw.com/pub/unix/tcsh/old/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/old/ \
		http://www.ccitt5.net/archives/:bofh
DISTFILES=	tcsh-6.12.00.tar.gz \
		tcsh-6.12.00-bofh.tgz:bofh

MAINTAINER=	pyzmen@kam.pl
COMMENT=	Patch tcsh to providing user activity logging to syslog

WRKSRC=		${WRKDIR}/tcsh-${PORTVERSION}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tcsh

pre-configure:
	@cd ${WRKSRC} && ${PATCH} -p1 < ../6.12.00/tcsh-6.12.00-bofh

.include <bsd.port.mk>
