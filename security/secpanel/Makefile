# New ports collection makefile for:	secpanel
# Date created:				11 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	secpanel
PORTVERSION=	0.41
CATEGORIES=	security tcl84 tk84
MASTER_SITES=	http://www.pingx.net/secpanel/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		ssh-askpass:${PORTSDIR}/security/openssh-askpass

USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's!^exec wish!exec wish8.4!; \
	s!\[file dirname \[info script\]\]/../lib/secpanel!${PREFIX}/share/secpanel! ; \
	s!askpassbin askpass!askpassbin ssh-askpass!' ${WRKSRC}/src/bin/secpanel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/secpanel ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/secpanel
.for file in convert_history.tcl default.config default.profile \
	gui.tcl keydistribute.tcl listserver.tcl secpanel.dist secpanel.wait
	${INSTALL_SCRIPT} ${WRKSRC}/src/lib/secpanel/${file} ${PREFIX}/share/secpanel
.endfor
	@${MKDIR} ${PREFIX}/share/secpanel/images
.for file in arrow_left.gif arrow_right.gif configs.gif connects.gif \
	folder.gif keys.gif profiles.gif scp.gif sscreen.gif
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/images/${file} \
		${PREFIX}/share/secpanel/images
.endfor

.include <bsd.port.mk>
