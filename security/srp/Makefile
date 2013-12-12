# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	srp
PORTVERSION=	2.1.2
CATEGORIES=	security net
MASTER_SITES=	http://srp.stanford.edu/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure Remote Password protocol library, TELNET, and FTP

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* krb5-maint-[0-9]* heimdal-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL="/usr/bin/install -C"
CONFIGURE_ARGS=	--with-openssl=/usr				\
		--with-zlib					\
		--enable-loginf

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
	@${GREP} -slR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib\.h|g'
	@${REINPLACE_CMD} -e 's/^struct.*\*sgetspent.*(const.*//' ${WRKSRC}/base/lib/shadow_.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
