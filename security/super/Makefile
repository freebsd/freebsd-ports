# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	super
PORTVERSION=	3.30.2
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.ucolick.org/pub/users/will/ \
		http://www.ucolick.org/~will/RUE/super/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Allow others to run commands as root

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/Copying

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="${PREFIX}/var"

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|\.\/mkdir_p -p755|mkdir -p -m 755|g' \
		-e '/sysconfdir/ s|super\.tab|&.sample|' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/super ${STAGEDIR}${PREFIX}/bin/setuid

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.tab ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.cdmount ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
