# New ports collection makefile for:    ztelnet
# Version required:     1.0p2
# Date created:         15 Mar 1998
# Whom:                 CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.3 1998/03/16 07:22:11 steve Exp $
#
# In this ports..
#   - new compilation diff for FreeBSD(now we can upload!)
#   - linux patch(implied -8 and stairway effect) is applied
# NOTE: in post-patch, we can ignore warnings.

DISTNAME=	ztelnet2
PKGNAME=	ko-ztelnet-1.0p2
CATEGORIES=	korean net
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/net/
DISTFILES=	ztelnet-linux.tar.gz ztelnet-patch.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1
MAN1=			ztelnet.1

post-patch:
	@( cd ${WRKSRC}/ztelnet && \
	${PATCH} -s -p1 < ${WRKSRC}/ztelnet.patch || \
	true ) > /dev/null 2>&1

do-build:
	@cd ${WRKSRC}/ztelnet && \
	${MAKE} clean && \
	${MAKE} 4.4bsd

do-install:
	@cd ${WRKSRC}/ztelnet; \
	${MKDIR} ${PREFIX}/bin; \
	${INSTALL_PROGRAM} telnet/telnet ${PREFIX}/bin/ztelnet
	${INSTALL_MAN} ${WRKDIR}/ztelnet/telnet/telnet.1 ${PREFIX}/man/man1/ztelnet.1

.include <bsd.port.mk>
