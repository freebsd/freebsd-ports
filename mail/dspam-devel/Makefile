# New ports collection makefile for:	dspam
# Date created:			3 August 2003
# Whom:				Dominic Marks <dom@wirespeed.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dspam
PORTVERSION=	2.7.1
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/

MAINTAINER=	dom@wirespeed.org.uk
COMMENT=	A server-side bayesian spam filter

LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-userdir=${PREFIX}/etc/dspam \
		--with-db4-includes=${LOCALBASE}/include/db41
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBTOOLFLAGS%%|${LIBTOOLFLAGS}|g ; \
		s|-ldb-4.1|-ldb41|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGE \
		${DOCSDIR}
.endif
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
