# New ports collection makefile for:    ztelnet
# Version required:     1.0p3
# Date created:         15 Mar 1998
# Whom:                 CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.5 1998/03/19 06:12:38 obrien Exp $
#
# In this ports..
#   - new compilation diff for FreeBSD(now we can upload!)
#   - linux patch(implied -8 and stairway effect) is applied
#   - improved sz and rz patch, and new ztelnet manpage(cmascott patch)
#     Thanks to Carl Mascott <cmascott@world.std.com>
# NOTE: in first post-patch, we can ignore warnings.

DISTNAME=	ztelnet2
PKGNAME=	ztelnet-1.0p3
CATEGORIES=	net
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/net/ztelnet/
DISTFILES=	ztelnet-linux.tar.gz ztelnet-patch.tar.gz \
		ztelnet-patch-cmascott.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1
MAN1=		ztelnet.1

post-patch:
	# we can ignore warnings
	@( cd ${WRKSRC}/ztelnet && \
	${PATCH} -s -p1 < ${WRKSRC}/ztelnet.patch || \
	true ) > /dev/null 2>&1
	# but it is not
	@cd ${WRKSRC}/ztelnet && \
	${PATCH} -s -p1 < ${WRKSRC}/rz.patch && \
	${PATCH} -s -p1 < ${WRKSRC}/sz.patch

do-build:
	@cd ${WRKSRC}/ztelnet && \
	${MAKE} clean && \
	${MAKE} 4.4bsd

do-install:
	@cd ${WRKSRC}/ztelnet; \
	${MKDIR} ${PREFIX}/bin; \
	${INSTALL_PROGRAM} telnet/telnet ${PREFIX}/bin/ztelnet
	${INSTALL_MAN} ${WRKSRC}/ztelnet.1 ${PREFIX}/man/man1/ztelnet.1

.include <bsd.port.mk>
