# Ports collection makefile for:  slush
# Version required:     	  0.1.0
# Date created:			  Sun May 3, 1999
# Whom:                 	shipley@dis.org
#
# $Id: Makefile,v 1.1.1.1 1999/05/09 17:50:05 steve Exp $
#

DISTNAME=	slush-0_1_0
PKGNAME=	slush-0.1.0
CATEGORIES=	security net
MASTER_SITES=	ftp://www.dis.org/pub/Security/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	shipley@dis.org

BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl

#MAN=		slush.1

GNU_CONFIGURE=	yes

#NOPROFILE=	true

.include <bsd.port.pre.mk>
.if ${OSVERSION} <= 300000
BROKEN=		does not build
.endif

WRKSRC=		${WRKDIR}/slush-0.1.0
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
MAKE_ENV+=	EXTRA_SSL_LIBS="-lRSAglue -lrsaref"
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/control.txt ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/HISTORY ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/slush
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/slush ${PREFIX}/bin/slush
	${INSTALL_PROGRAM} ${WRKSRC}/slushd ${PREFIX}/sbin/slushd

.include <bsd.port.post.mk>
