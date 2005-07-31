# New ports collection makefile for:	openct
# Date created:		2004-09-08
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	openct
PORTVERSION=	0.6.5
CATEGORIES=	security
MASTER_SITES=	http://www.opensc.org/files/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A middleware framework for smart card terminals

USE_LIBTOOL_VER=	15
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

MAN1=		openct-tool.1

DOC_FILES=	README export-wiki.sh export-wiki.xsl ${HTML_FILES}

HTML_FILES=	AuthorsAndCredits.html FilesTools.html LicenseText.html \
	OperatingSystems.html QuickStart.html RecentResults.html \
	RemoteAccess.html SecureSetup.html SupportedReaders.html \
	TroubleShooting.html cardman.html ccid.html egate.html \
	etoken.html eutron.html gempc.html ikey2032.html \
	ikey3000.html index.html kaan.html smartboard.html \
	towitoko.html trac.css

.if !defined(WITHOUT_PCSC_LITE)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
.endif

post-install:
	#run files
	${MKDIR} /var/run/${PORTNAME}
	#sample config file
	${INSTALL_DATA}	${WRKSRC}/etc/openct.conf ${PREFIX}/etc/openct.conf-sample
	#start daemons script
	${INSTALL_SCRIPT} ${WRKSRC}/etc/init-script ${PREFIX}/etc/rc.d/openct.sh
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
.endif

.include <bsd.port.mk>
