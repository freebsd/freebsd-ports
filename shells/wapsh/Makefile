# New ports collection makefile for:   wapsh
# Date created:        13 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	wapsh
PORTVERSION=	1.0.1
CATEGORIES=	shells
MASTER_SITES=	http://www.exolution.de/geschaeft/produkte/wapsh/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	A system to allow remote shell logins via a WAP phone or web browser

USE_RC_SUBR=	htshd.sh

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

WWWOWN?=	www
WWWGRP?=	www
WWWDIR?=	www/${PORTNAME}
DATADIR=	${PREFIX}/${WWWDIR}
SUB_FILES=	pkg-message

USERGUIDEDOCS=	Image10.jpg Image11.jpg Image12.jpg Image13.jpg \
		Image14.jpg Image15.jpg Image16.jpg Image17.jpg \
		Image18.jpg Image19.jpg Image20.jpg Image21.jpg \
		Image22.jpg Image23.jpg Image24.jpg Image25.gif \
		Image26.jpg Image27.jpg Image28.jpg Image29.jpg \
		Image30.jpg Image31.jpg Image32.jpg Image33.jpg \
		Image34.jpg Image35.jpg Image36.jpg Image37.jpg \
		Image38.jpg Image39.jpg Image4.gif Image40.jpg  \
		Image41.jpg Image42.jpg Image43.jpg Image44.jpg \
		Image45.jpg Image46.jpg Image47.jpg Image48.jpg \
		Image49.jpg Image5.gif Image50.gif Image51.jpg  \
		Image52.jpg Image53.gif Image54.jpg Image55.jpg \
		Image56.jpg Image6.jpg Image7.jpg Image8.jpg    \
		Image9.jpg index.html

HTDOCS=		command.php command_html.inc command_wml.inc          \
		common.inc common_html.inc common_wml.inc             \
		controls_wml.php displayfuncs.inc getloginhosts.inc   \
		history_edit_wml.php history_html.php history_wml.php \
		login_html.php login_wml.php scroll_wml.php           \
		shortcuts_wml.php index.html

post-patch:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/htshd/htshd.c > ${WRKDIR}/foo && \
		${MV} ${WRKDIR}/foo ${WRKSRC}/htshd/htshd.c

do-build:
	(cd ${WRKSRC}/htshd && ${CC} ${CFLAGS} -o htshd htshd.c -lcrypt \
		-lutil -DUSE_DEV_RANDOM=1 -DHAVE_SETENV)

pre-install:
	@${ECHO_MSG} "----------------------------------------------------------------"
	@${ECHO_MSG} "Set WWWDIR to the location of your web server's document root,"
	@${ECHO_MSG} "relative to ${PREFIX}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PORTNAME} will be installed under ${PREFIX}/\$$WWWDIR/"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The current value of WWWDIR is: ${WWWDIR}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL+C now to change it."
	@${ECHO_MSG} "----------------------------------------------------------------"
	@sleep 2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htshd/htshd ${PREFIX}/sbin

	${MKDIR} ${PREFIX}/etc/wapsh
.for C in htsh_profile htshd.conf loginhosts
	${INSTALL_DATA} ${WRKSRC}/sample/$C ${PREFIX}/etc/wapsh/$C.dist
	if [ ! -e ${PREFIX}/etc/wapsh/$C ]; then \
		${CP} ${PREFIX}/etc/wapsh/$C.dist \
			${PREFIX}/etc/wapsh/$C; \
	fi
.endfor

	${MKDIR} ${DATADIR}
.for H in ${HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/$H ${DATADIR}
.endfor
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/admin_guide
	${MKDIR} ${DOCSDIR}/implementation_notes
	${MKDIR} ${DOCSDIR}/user_guide
.for B in Image1.jpg Image2.jpg Image3.jpg index.html qpl.html
	${INSTALL_DATA} ${WRKSRC}/docs/html/$B ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/html/admin_guide/index.html \
		${DOCSDIR}/admin_guide
.for I in index.html image57.gif
	${INSTALL_DATA} ${WRKSRC}/docs/html/implementation_notes/$I \
		${DOCSDIR}/implementation_notes
.endfor
.for U in ${USERGUIDEDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/html/user_guide/$U \
		${DOCSDIR}/user_guide
.endfor
.endif #if !defined(NOPORTDOCS)

post-install:
	@${ECHO} "updating /etc/services"
	@${CP} /etc/services /etc/services.bak
	@(${GREP} -v ^htsh /etc/services.bak; ${ECHO_CMD} "htsh		3001/tcp    # htsh/wapsh server") > /etc/services
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
