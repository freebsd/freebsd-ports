# New ports collection makefile for:	srp
# Date created:							07/25/2001
# Whom:									nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	srp
PORTVERSION=	2.1.2
CATEGORIES=	security net
MASTER_SITES=	http://srp.stanford.edu/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure Remote Password protocol library, TELNET, and FTP

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* heimdal-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL="/usr/bin/install -C"
CONFIGURE_ARGS=	--with-openssl=/usr				\
		--with-zlib					\
		--enable-loginf

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -slR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib\.h|g'
.if ${OSVERSION} >= 700042
	@${REINPLACE_CMD} -e 's/^struct.*\*sgetspent.*(const.*//' ${WRKSRC}/base/lib/shadow_.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
