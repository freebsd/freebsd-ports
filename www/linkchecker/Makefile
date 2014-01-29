# Created by: ijliao
# $FreeBSD$

PORTNAME=	linkchecker
PORTVERSION=	8.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	GHC
DISTNAME=	LinkChecker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check HTML documents for broken links

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:${PORTSDIR}/dns/py-dnspython

OPTIONS_DEFINE=	CLAMAV GEOIP GTK2 LOGIN QT4 SQLITE3 SYNTAX WSGI NLS EXAMPLES
OPTIONS_DEFAULT=SQLITE3 SYNTAX
CLAMAV_DESC=	Clam Antivirus
LOGIN_DESC=	Login form submission
SYNTAX_DESC=	HTML/CSS syntax check
WSGI_DESC=	WSGI Web interface

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	wummel

USE_XZ=		yes
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	LinkChecker
PYEASYINSTALL_ARCHDEP=	yes
INSTALLS_ICONS=	yes

MANLANG=	"" de
MAN1=		linkchecker.1
MAN5=		linkcheckerrc.5

NO_STAGE=	yes
.include <bsd.port.options.mk>

# For Virus checking
.if ${PORT_OPTIONS:MCLAMAV}
RUN_DEPENDS+=	clamscan:${PORTSDIR}/security/clamav
.endif

# For displaying country codes
.if ${PORT_OPTIONS:MGEOIP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}GeoIP>0:${PORTSDIR}/net/py-GeoIP
.endif

# For GNOME proxy setting parsing
.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	pygtk2
.endif

# For login form submission
.if ${PORT_OPTIONS:MLOGIN}
RUN_DEPENDS+=	twill:${PORTSDIR}/www/twill
.endif

# For Graphical User Interface
.if ${PORT_OPTIONS:MQT4}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-sql>=${PYQT_VERSION}:${PORTSDIR}/databases/py-qt4-sql \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-help>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-help \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=${QSCI2_VERSION}:${PORTSDIR}/devel/py-qt4-qscintilla2
PLIST_SUB+=	QT4=""
MAN1+=		linkchecker-gui.1
.else
PLIST_SUB+=	QT4="@comment "
.endif

# For parsing bookmark files
.if ${PORT_OPTIONS:MSQLITE3}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

# For HTML/CSS syntax checks
.if ${PORT_OPTIONS:MSYNTAX}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.5:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}utidy>=0.2:${PORTSDIR}/www/py-utidy
.endif

# To run the WSGI Web interface
.if ${PORT_OPTIONS:MWSGI}
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_wsg2>0:${PORTSDIR}/www/mod_wsgi2
USE_APACHE_RUN=	22
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=linkchecker|' ${WRKSRC}/doc/*.desktop

post-build:
	@${MKDIR} ${WRKDIR}/site-packages
	@${CAT} ${WRKSRC}/_LinkChecker_configdata.py | ${GREP} ^# \
		> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "install_purelib = '${PYTHONPREFIX_SITELIBDIR}'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "install_platlib = '${PYTHONPREFIX_SITELIBDIR}'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "install_lib = '${PYTHONPREFIX_SITELIBDIR}'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "install_headers = '${PYTHONPREFIX_INCLUDEDIR}/LinkChecker'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "install_scripts = '${PREFIX}/bin'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "config_dir = '${DATADIR}'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${ECHO_MSG} "install_data = '${PREFIX}'" \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${CAT} ${WRKSRC}/_LinkChecker_configdata.py | \
		${GREP} -v ^# | ${GREP} -v ^install | ${GREP} -v ^config \
		>> ${WRKDIR}/site-packages/_LinkChecker_configdata.py
	@${PYTHON_CMD} -m compileall ${WRKDIR}/site-packages
	@${PYTHON_CMD} -O -m compileall ${WRKDIR}/site-packages
.if ${PORT_OPTIONS:MNLS}
.for lang in de es fr
	(cd ${WRKSRC}/po && msgfmt -c -o ${lang}.mo ${lang}.po)
.endfor
.endif

post-install:
	(cd ${WRKDIR}/site-packages && ${INSTALL_DATA} \
		_LinkChecker_configdata.py* \
		${PYTHONPREFIX_SITELIBDIR})
	(cd ${WRKDIR}/site-packages && ${INSTALL_DATA} \
		_LinkChecker_configdata.py* \
		${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG})
	(cd ${WRKSRC}/doc/en && ${INSTALL_MAN} linkchecker.1 \
		${MAN1PREFIX}/man/man1)
	(cd ${WRKSRC}/doc/en && ${INSTALL_MAN} linkcheckerrc.5 \
		${MAN5PREFIX}/man/man5)
	@${MKDIR} ${MAN1PREFIX}/man/de/man1
	(cd ${WRKSRC}/doc/de && ${INSTALL_MAN} linkchecker.1 \
		${MAN1PREFIX}/man/de/man1)
	@${MKDIR} ${MAN5PREFIX}/man/de/man5
	(cd ${WRKSRC}/doc/de && ${INSTALL_MAN} linkcheckerrc.5 \
		${MAN5PREFIX}/man/de/man5)
.for i in 16 32 48 64 128
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/doc/html && ${INSTALL_DATA} logo${i}x${i}.png \
		${PREFIX}/share/icons/hicolor/${i}x${i}/apps/linkchecker.png)
.endfor
	@${MKDIR} ${DATADIR}
.for i in ca-certificates.crt linkcheckerrc
	(cd ${WRKSRC}/config && ${INSTALL_DATA} ${i} ${DATADIR})
.endfor
.for i in lccollection.qhc lcdoc.qch
	(cd ${WRKSRC}/doc/html && ${INSTALL_DATA} ${i} ${DATADIR})
.endfor
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} linkchecker.desktop \
		${DESKTOPDIR})
.if ${PORT_OPTIONS:MQT4}
	(cd ${WRKSRC}/doc/en && ${INSTALL_MAN} linkchecker-gui.1 \
		${MAN1PREFIX}/man/man1)
	(cd ${WRKSRC}/doc/de && ${INSTALL_MAN} linkchecker-gui.1 \
		${MAN1PREFIX}/man/de/man1)
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} linkchecker-gui.desktop \
		${DESKTOPDIR})
.endif
.if ${PORT_OPTIONS:MNLS}
.for lang in de es fr
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/linkchecker.mo)
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/cgi-bin/lconline && ${INSTALL_DATA} * ${EXAMPLESDIR})
.for i in linkchecker.apache2.conf linkchecker-completion
	(cd ${WRKSRC}/config && ${INSTALL_DATA} ${i} ${EXAMPLESDIR})
.endfor
.for i in check_blacklist.sh check_for_x_errors.sh check_urls.sh
	(cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} ${i} ${EXAMPLESDIR})
.endfor
.endif

.include <bsd.port.mk>
