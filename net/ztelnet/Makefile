# New ports collection makefile for:    ztelnet
# Version required:     1.0p1
# Date created:         4 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 09:02:45 asami Exp $
#

DISTNAME=	ztelnet
PKGNAME=	ko-ztelnet-1.0p1
CATEGORIES=	korean net
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/network/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/network/ \
		ftp://jazz.snu.ac.kr/pub/unix/util/net/
DISTFILES=	ztelnet.tar.gz ztelnet-patch.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

post-patch:
	@cd ${WRKDIR}; \
	${PATCH} --quiet < ${FILESDIR}/ztelnet.patch.patch; \
	${PATCH} --quiet < ztelnet.patch

do-install:
	@cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/bin; \
	${INSTALL_PROGRAM} telnet/telnet ${PREFIX}/bin/ztelnet

.include <bsd.port.mk>
