# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.9.2
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/2515/

MAINTAINER=	kelley@insidesystems.net
COMMENT=	Easy to set up wiki clone implemented in ruby

NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8
INSTIKIDIR?=	instiki

PLIST_SUB=      INSTIKIDIR=${INSTIKIDIR}/

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%INSTIKIDIR%%,${INSTIKIDIR},g' \
		-e 's,%%INSTIKIPORT%%,${INSTIKIPORT},g' \
		-e 's,%%RUBY_WITHOUT_SUFFIX%%,${RUBY_WITHOUT_SUFFIX},g'

INSTIKIPORT?=	2500

pre-install:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

do-install:
	${CP} -pR ${WRKSRC}/ ${PREFIX}/${INSTIKIDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	${MKDIR} ${PREFIX}/${INSTIKIDIR}/storage/${INSTIKIPORT}
	${CHMOD} +x ${PREFIX}/${INSTIKIDIR}/instiki
# Use 'col' to ditch the DOS control characters (for version 0.9.2, this could change)
	${CAT} ${PREFIX}/${INSTIKIDIR}/instiki | col > ${PREFIX}/${INSTIKIDIR}/instiki

.include <bsd.port.mk>
