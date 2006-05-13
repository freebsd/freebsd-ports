# New ports collection makefile for:	srp
# Date created:							07/25/2001
# Whom:									nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	srp
PORTVERSION=	2.1.1
CATEGORIES=	security net
MASTER_SITES=	http://srp.stanford.edu/source/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Secure Remote Password protocol library, TELNET, and FTP

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL="/usr/bin/install -C"
CONFIGURE_ARGS=	--with-openssl=/usr				\
		--with-zlib					\
		--enable-loginf

post-patch:
	@${GREP} -slR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib\.h|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
