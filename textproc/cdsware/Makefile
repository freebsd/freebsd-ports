# New ports collection makefile for:	cdsware
# Date created:		21 jun 2004
# Whom:			thierry@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cdsware
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	http://cdsware.cern.ch/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CERN Document Server Software

BUILD_DEPENDS=	${RUN_DEPENDS}	# Checked by configure
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_mysql.so:${PORTSDIR}/databases/py-MySQLdb	\
		${PYTHON_SITELIBDIR}/mod_python/_psp.so:${PORTSDIR}/www/mod_python3 \
		${LOCALBASE}/bin/wml:${PORTSDIR}/www/wml	\
		${PYNUMERIC}

BROKEN=		"Conflicting dependencies: apache 1.x and apache 2.x"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

.if !defined(WITHOUT_X11)
. if !defined(WITHOUT_XPDF)
RUN_DEPENDS+=	${X11BASE}/bin/pdftotext:${PORTSDIR}/graphics/xpdf
. endif
. if !defined(WITHOUT_ACROREAD)
RUN_DEPENDS+=	${X11BASE}/bin/acroread5:${PORTSDIR}/print/acroread
. endif
. if !defined(WITHOUT_WV)
RUN_DEPENDS+=	${LOCALBASE}/bin/wvHtml:${PORTSDIR}/textproc/wv
. endif
. if !defined(WITHOUT_XL)
RUN_DEPENDS+=	${LOCALBASE}/bin/xlhtml:${PORTSDIR}/textproc/xlhtml
. endif
.endif

.if !defined(WITHOUT_H2T)
RUN_DEPENDS+=	${LOCALBASE}/bin/html2text:${PORTSDIR}/textproc/html2text
.endif

.if !defined(WITHOUT_IM)
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if !defined(WITHOUT_PS)
RUN_DEPENDS+=	${LOCALBASE}/bin/pstotext:${PORTSDIR}/print/pstotext
.endif

.if !defined(WITHOUT_UNGIF)
RUN_DEPENDS+=	${LOCALBASE}/bin/giftext:${PORTSDIR}/graphics/libungif
.endif

.if exists(${LOCALBASE}/bin/antiword)
WITH_ANTIWORD=	yes
.endif
.if defined(WITH_ANTIWORD)
RUN_DEPENDS+=	${LOCALBASE}/bin/antiword:${PORTSDIR}/textproc/antiword
.endif

.if exists(${LOCALBASE}/bin/catdoc)
WITH_CATDOC=	yes
.endif
.if defined(WITH_CATDOC)
RUN_DEPENDS+=	${LOCALBASE}/bin/catdoc:${PORTSDIR}/textproc/catdoc
.endif

.if exists(${LOCALBASE}/bin/catdoc)
WITH_CATDOC=	yes
.endif
.if defined(WITH_CATDOC)
RUN_DEPENDS+=	${LOCALBASE}/bin/catdoc:${PORTSDIR}/textproc/catdoc
.endif

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/cdsware		\
			--localstatedir=/var			\
			--with-webdir=${PREFIX}/${WEBDIR}	\
			--with-weburl=http://${WHOST}/${WALIAS}	\
			--with-dbhost=${DBHOST}			\
			--with-dbname=${DBNAME}			\
			--with-dbuser=${DBUSER}			\
			--with-dbpass=${DBPASS}			\
			--with-python=${PYTHON_CMD}

USE_GMAKE=		yes
USE_APACHE=		yes
WITH_APACHE2=		yes
USE_PHP=		zlib pcntl mysql xml
WANT_PHP_MOD=		yes
WANT_PHP_CLI=		yes
USE_MYSQL=		yes
USE_PYTHON=		2.3+
USE_REINPLACE=		yes
.if !defined(PACKAGE_BUILDING)
# 4.1 recommended due to its UTF-8 support, but conflicts with py-MySQLdb
WANT_MYSQL_VER=		41
.endif

WEBDIR?=	www/cdsware
WALIAS?=	cdsware
WHOST?=		${unamen}
DBHOST?=	localhost
DBNAME?=	cdsware
DBUSER?=	cdsware
DBPASS?=	Change_On_Install
CDSNAME?=	FreeBSD Ports Document Server (To be changed in config.wml)
ALERTEMAIL?=	cds.alert@${unamen}
SUPPORTEMAIL?=	cds.support@${unamen}
ADMINEMAIL?=	cds.admin@${unamen}

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	WEBDIR=${WEBDIR}

APACHE_CONF=	${LOCALBASE}/etc/apache2/httpd.conf
CDSWARE_INC=	${PREFIX}/etc/${PORTNAME}
LCDSWARE_CNF=	config.wml
CDSWARE_CNF=	${PREFIX}/${PORTNAME}/lib/wml/${PORTNAME}/${LCDSWARE_CNF}
CDSBIN=		${PREFIX}/${PORTNAME}/bin

AVAIL_LANG=	de en es pt fr it ru sk cz no se
UTILSQL=	tabbibclean.sql tabcreate.sql tabdrop.sql tabfill.sql
DEMODAT=	demobibdata.xml democfgdata.sql
PORTDOCS=	AUTHORS INSTALL NEWS README TODO UNINSTALL

.include <bsd.port.pre.mk>

.if defined(LANG)
. for i in ${AVAIL_LANG}
.  if ${LANG:M${i}*} != ""
CDSLANG=	${i}
.  endif
. endfor
.endif
CDSLANG?=	en

unamen!=	${UNAME} -n

.if ${ARCH} == i386
RUN_DEPENDS+=		${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "CDSware will be installed with these options:"
	@${ECHO_MSG} "Variable	Meaning				Default"
	@${ECHO_MSG} "WEBDIR	Directory holding the web interface	${WEBDIR}"
	@${ECHO_MSG} "		(under ${PREFIX}/)"
	@${ECHO_MSG} "WALIAS	Alias of WEBDIR, to define the URL	${WALIAS}"
	@${ECHO_MSG} "WHOST	Hostname of your web server		${WHOST}"
	@${ECHO_MSG} "		=> The URL will be http://${WHOST}/${WALIAS}"
	@${ECHO_MSG} "DBHOST	Hostname of your database server	${DBHOST}"
	@${ECHO_MSG} "DBNAME	MySQL database name			${DBNAME}"
	@${ECHO_MSG} "DBUSER	MySQL database user			${DBUSER}"
	@${ECHO_MSG} "DBPASS	MySQL password				${DBPASS}"
	@${ECHO_MSG}
	@${ECHO_MSG} "CDSNAME	The visible name of your CDSware installation"
	@${ECHO_MSG}
	@${ECHO_MSG} "To change these values, press Ctrl-C now and define your variables."

pre-configure:
.for wh in admin/howto/run.html.wml hacking/directory.html.wml
	@${REINPLACE_CMD} -e "s|/usr/local/cdsware-DEMO/var|/var|"	\
		-e "s|/usr/local/cdsware-DEMO|${PREFIX}/cdsware|"	\
		${WRKSRC}/modules/webhelp/web/${wh}
.endfor

post-configure:
.if exists(${CDSWARE_CNF}.previous)	# Restore previous config file
	@${MV} ${CDSWARE_CNF}.previous ${WRKSRC}/config/${LCDSWARE_CNF}
.else
	@${REINPLACE_CMD} -e "s|%%CDSNAME%%|${CDSNAME}|"		\
		-e "s|%%CDSLANG%%|${CDSLANG}|;s|%%PREFIX%%|${PREFIX}|"	\
		-e "s|%%ALERTEMAIL%%|${ALERTEMAIL}|"			\
		-e "s|%%SUPPORTEMAIL%%|${SUPPORTEMAIL}|"		\
		-e "s|%%ADMINEMAIL%%|${ADMINEMAIL}|"			\
		${WRKSRC}/config/${LCDSWARE_CNF}
.endif

post-install:
	@${CHMOD} go-rx ${CDSBIN}/dbexec
	@for p in `${LS} ${CDSBIN}` ;			\
	do						\
		${LN} -sf ${CDSBIN}/$$p ${PREFIX}/bin ;	\
	done
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${WEBDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/cdsware/lib/python
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/cdsware/lib/python
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WEBDIR} /var/cache/cdsware	\
		/var/log/cdsware /var/tmp/cdsware /var/data/cdsware
	@${CP} -p ${CDSWARE_CNF} ${CDSWARE_CNF}.sample
	@${MKDIR} ${DATADIR}
	@${SED} -e "s|%%DBNAME%%|${DBNAME}|;s|%%DBUSER%%|${DBUSER}|;	\
		s|%%DBPASS%%|${DBPASS}|"				\
		< ${FILESDIR}/create-db.sql > ${DATADIR}/create-db.sql
	${INSTALL_DATA} ${UTILSQL:S|^|${WRKSRC}/modules/miscutil/sql/|} ${DATADIR}
	${INSTALL_DATA} ${DEMODAT:S|^|${WRKSRC}/modules/miscutil/demo/|} ${DATADIR}
	@${ECHO_MSG} "===> Utilities installed in ${DATADIR}."
	@(if [ -f ${APACHE_CONF} ] ; then \
		${MKDIR} ${CDSWARE_INC} ; \
		${SED} -e "s|%%PREFIX%%|${PREFIX}|;s|%%WEBDIR%%|${WEBDIR}|;"		\
			-e "s|%%WALIAS%%|${WALIAS}|" < ${FILESDIR}/httpd.conf.cdsware	\
			> ${CDSWARE_INC}/httpd.conf.cdsware ; \
		${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
		${CP} -p ${APACHE_CONF} ${APACHE_CONF}.beforeCDSware ; \
		if ! ${GREP} -q python_module ${APACHE_CONF} ; then \
			${ECHO_CMD} "LoadModule python_module libexec/apache2/mod_python.so" \
				>> ${APACHE_CONF} ; \
		fi ; \
		${ECHO_CMD} "# CDSware's include directory" >> ${APACHE_CONF} ; \
		${ECHO_CMD} "Include ${CDSWARE_INC}" >> ${APACHE_CONF} ; \
	fi)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
	@${ECHO_MSG}
	@${SED} -e "s|%%ADMINEMAIL%%|${ADMINEMAIL}|"	\
		< ${FILESDIR}/pkg-message.in		\
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

# Targets copied from ${WRKSRC}/Makefile, to be used without rebuilding everything
create-db:
	mysql -h ${DBHOST} -u root -p < ${DATADIR}/create-db.sql

create-tables:
	${CDSBIN}/dbexec < ${DATADIR}/tabcreate.sql
	${CDSBIN}/dbexec < ${DATADIR}/tabfill.sql

create-demo-site:
	${CDSBIN}/dbexec < ${DATADIR}/democfgdata.sql
	${ECHO} "TRUNCATE schTASK;" | ${CDSBIN}/dbexec
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "You will be asked for a username, please enter ${ADMINEMAIL} below."
	@${ECHO_MSG} "***********************************************************************"
	${CDSBIN}/webcoll
	${CDSBIN}/webcoll 1
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "** The demo site has been successfully created.                      **"
	@${ECHO_MSG} "**                                                                   **"
	@${ECHO_MSG} "** Please point your browser to http://${WHOST}/${WALIAS}/"
	@${ECHO_MSG} "** It should ressemble our 'Atlantis Institute of Fictive Science'   **"
	@${ECHO_MSG} "** demo site that is available at <http://cdsware.cern.ch/demo/>,    **"
	@${ECHO_MSG} "** with the exception that no demo records have been loaded yet.     **"
	@${ECHO_MSG} "**                                                                   **"
	@${ECHO_MSG} "** To load demo records, you can run 'make load-demo-records'.       **"
	@${ECHO_MSG} "** To drop the demo site, you can run 'make drop-demo-site'.         **"
	@${ECHO_MSG} "***********************************************************************"

load-demo-records:
	${CDSBIN}/dbexec < ${DATADIR}/tabbibclean.sql
	${ECHO} "TRUNCATE schTASK;" | ${CDSBIN}/dbexec
	${CDSBIN}/bibupload -i ${DATADIR}/demobibdata.xml
	${CDSBIN}/bibupload 1
	@${ECHO_MSG} ""
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "You will be asked for a username, please enter ${ADMINEMAIL} below."
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} ""
	${CDSBIN}/bibindex
	${CDSBIN}/bibindex 2
	@${ECHO_MSG} ""
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "You will be asked for a username, please enter ${ADMINEMAIL} below."
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} ""
	${CDSBIN}/bibreformat -oHB,HD,HP,HC
	${CDSBIN}/bibreformat 3
	${CDSBIN}/bibupload 4
	@${ECHO_MSG} ""
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "You will be asked for a username, please enter ${ADMINEMAIL} below."
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} ""
	${CDSBIN}/webcoll
	${CDSBIN}/webcoll 5
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "** The demo records have been successfully loaded.                   **"
	@${ECHO_MSG} "**                                                                   **"
	@${ECHO_MSG} "** Please point your browser to http://${WHOST}/${WALIAS}/"
	@${ECHO_MSG} "** It should ressemble our 'Atlantis Institute of Fictive Science'   **"
	@${ECHO_MSG} "** demo site that is available at <http://cdsware.cern.ch/demo/>.    **"
	@${ECHO_MSG} "**                                                                   **"
	@${ECHO_MSG} "** To remove demo records, you can run 'make remove-demo-records'.   **"
	@${ECHO_MSG} "** To drop also the demo site collection etc configurations,         **"
	@${ECHO_MSG} "** you can run 'make drop-demo-site'.                                **"
	@${ECHO_MSG} "***********************************************************************"

remove-demo-records:
	${CDSBIN}/dbexec < ${DATADIR}/tabbibclean.sql
	${ECHO} "TRUNCATE schTASK;" | ${CDSBIN}/dbexec
	@${ECHO_MSG} ""
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "You will be asked for a username, please enter ${ADMINEMAIL} below."
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} ""
	${CDSBIN}/webcoll
	${CDSBIN}/webcoll 1
	@${ECHO_MSG} "**********************************************************"
	@${ECHO_MSG} "** The demo records have been successfully removed.     **"
	@${ECHO_MSG} "** The demo collection and submit configurations        **"
	@${ECHO_MSG} "** have been preserved.                                 **"
	@${ECHO_MSG} "**                                                      **"
	@${ECHO_MSG} "** Note that you can run 'make drop-demo-site' to drop  **"
	@${ECHO_MSG} "** the demo site fully.                                 **"
	@${ECHO_MSG} "**********************************************************"

drop-demo-site:
	${CDSBIN}/dbexec < ${DATADIR}/tabdrop.sql
	${CDSBIN}/dbexec < ${DATADIR}/tabcreate.sql
	${CDSBIN}/dbexec < ${DATADIR}/tabfill.sql
	${ECHO} "TRUNCATE schTASK;" | ${CDSBIN}/dbexec
	@${ECHO_MSG} ""
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "You will be asked for a username, please enter ${ADMINEMAIL} below."
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} ""
	${CDSBIN}/webcoll
	${CDSBIN}/webcoll 1
	@${ECHO_MSG} "***************************************************************"
	@${ECHO_MSG} "** The demo site and records have been successfully dropped. **"
	@${ECHO_MSG} "***************************************************************"

.include <bsd.port.post.mk>
