# New ports collection makefile for:	XSL stylesheets for DocBook
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xsl-docbook-modular
PORTVERSION=	1.24
CATEGORIES=	textproc
MASTER_SITES=	http://nwalsh.com/docbook/xsl/
DISTNAME=	dbx${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.zip
BROKEN=		use docbook-xsl instead

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/readme.txt:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xml/docbook/sdocbook/test.xml:${PORTSDIR}/textproc/sdocbook-xml \
		${LOCALBASE}/share/java/xt/xt.htm:${PORTSDIR}/textproc/xt \
		${LOCALBASE}/share/java/classes/xerces.jar:${PORTSDIR}/textproc/xerces-j \
		${LOCALBASE}/share/java/classes/fop.jar:${PORTSDIR}/textproc/fop

USE_ZIP=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/docbook
EXTRACT_BEFORE_ARGS=	-a -q

JDKVERSION?=	1.1.8
INSTDIR=	${PREFIX}/share/xml/docbook/xsl/modular

do-build:
	${RM} -rf ${WRKSRC}/docsrc
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%JDKVERSION%%|${JDKVERSION}|g' \
		${FILESDIR}/dbx2a.sh.tmpl > ${WRKSRC}/dbx2a.sh

pre-install:
	${MKDIR} ${INSTDIR}
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

do-install:
	${CP} -Rp ${WRKDIR}/docbook/* ${INSTDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}
	${CHMOD} ${BINMODE} ${INSTDIR}/dbx2a.sh
	${LN} -sf ${INSTDIR}/dbx2a.sh ${PREFIX}/bin/dbx2a

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.mk>
