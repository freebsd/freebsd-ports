# Created by: ijliao
# $FreeBSD$

PORTNAME=	linkchecker
PORTVERSION=	9.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
DISTNAME=	LinkChecker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check HTML documents for broken links

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>0:${PORTSDIR}/dns/py-dnspython

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	LinkChecker
PYEASYINSTALL_ARCHDEP=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		CLAMAV EXAMPLES GEOIP GTK2 LOGIN NLS QT4 \
			SQLITE3 SYNTAX WSGI
OPTIONS_DEFAULT=	SQLITE3 SYNTAX
OPTIONS_SUB=		yes

CLAMAV_DESC=		Clam Antivirus
CLAMAV_RUN_DEPENDS=	clamscan:${PORTSDIR}/security/clamav
GEOIP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}GeoIP>0:${PORTSDIR}/net/py-GeoIP
GTK2_USE=		gnome=pygtk2
LOGIN_DESC=		Login form submission
LOGIN_RUN_DEPENDS=	twill:${PORTSDIR}/www/twill
NLS_USES=		gettext
QT4_RUN_DEPENDS=\
		${PYTHON_PKGNAMEPREFIX}qt4-sql>=${PYQT_VERSION}:${PORTSDIR}/databases/py-qt4-sql \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-help>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-help \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>=${QSCI2_VERSION}:${PORTSDIR}/devel/py-qt4-qscintilla2
SQLITE3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
SYNTAX_DESC=		HTML/CSS syntax check
SYNTAX_RUN_DEPENDS=\
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.5:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}utidy>=0.2:${PORTSDIR}/www/py-utidy
WSGI_DESC=		WSGI Web interface
WSGI_RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_wsg2>0:${PORTSDIR}/www/mod_wsgi2
WSGI_USE=		apache_run=22

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MNLS}
.for lang in de es fr
	(cd ${WRKSRC}/po && msgfmt -c -o ${lang}.mo ${lang}.po)
.endfor
.endif

post-install:
	(cd ${WRKDIR}/site-packages && ${INSTALL_DATA} \
		_LinkChecker_configdata.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR})
	(cd ${WRKDIR}/site-packages && ${INSTALL_DATA} \
		_LinkChecker_configdata.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG})
	(cd ${WRKSRC}/doc/en && ${INSTALL_MAN} linkchecker.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1)
	(cd ${WRKSRC}/doc/en && ${INSTALL_MAN} linkcheckerrc.5 \
		${STAGEDIR}${MAN5PREFIX}/man/man5)
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/de/man1
	(cd ${WRKSRC}/doc/de && ${INSTALL_MAN} linkchecker.1 \
		${STAGEDIR}${MAN1PREFIX}/man/de/man1)
	@${MKDIR} ${STAGEDIR}${MAN5PREFIX}/man/de/man5
	(cd ${WRKSRC}/doc/de && ${INSTALL_MAN} linkcheckerrc.5 \
		${STAGEDIR}${MAN5PREFIX}/man/de/man5)
.for i in 16 32 48 64 128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/doc/html && ${INSTALL_DATA} logo${i}x${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/linkchecker.png)
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/config && ${INSTALL_DATA} linkcheckerrc \
		${STAGEDIR}${DATADIR})
.for i in lccollection.qhc lcdoc.qch
	(cd ${WRKSRC}/doc/html && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DATADIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} linkchecker.desktop \
		${STAGEDIR}${DESKTOPDIR})
.if ${PORT_OPTIONS:MQT4}
	(cd ${WRKSRC}/doc/en && ${INSTALL_MAN} linkchecker-gui.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1)
	(cd ${WRKSRC}/doc/de && ${INSTALL_MAN} linkchecker-gui.1 \
		${STAGEDIR}${MAN1PREFIX}/man/de/man1)
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} linkchecker-gui.desktop \
		${STAGEDIR}${DESKTOPDIR})
.endif
.if ${PORT_OPTIONS:MNLS}
.for lang in de es fr
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	(cd ${WRKSRC}/po && ${INSTALL_DATA} ${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/linkchecker.mo)
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/cgi-bin/lconline && ${INSTALL_DATA} * \
		${STAGEDIR}${EXAMPLESDIR})
.for i in linkchecker.apache2.conf linkchecker-completion
	(cd ${WRKSRC}/config && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${EXAMPLESDIR})
.endfor
.for i in check_blacklist.sh check_for_x_errors.sh check_urls.sh
	(cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${EXAMPLESDIR})
.endfor
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
