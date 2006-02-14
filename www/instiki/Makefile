# New ports collection makefile for:	instiki
# Date created:				4 January 2005
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	instiki
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://rubyforge.lauschmusik.de/instiki/	\
		http://rubyforge.planetargon.com/instiki/	\
		http://rubyforge.org/frs/download.php/5350/
EXTRACT_SUFX=	.tgz

MAINTAINER=	arsptr@optusnet.com.au
COMMENT=	Easy to set up wiki clone implemented in ruby

NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8
INSTIKIDIR?=	instiki

PLIST_SUB=	INSTIKIDIR=${INSTIKIDIR}/

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%INSTIKIDIR%%,${INSTIKIDIR},g' \
		-e 's,%%INSTIKIPORT%%,${INSTIKIPORT},g' \
		-e 's,%%RUBY_WITH_SUFFIX%%,${RUBY_WITH_SUFFIX},g'

RUBY_SHEBANG_FILES=instiki

INSTIKIPORT?=	2500

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-install:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

do-install:
	${CP} -pR ${WRKSRC}/ ${PREFIX}/${INSTIKIDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	${MKDIR} ${PREFIX}/${INSTIKIDIR}/storage/${INSTIKIPORT}
	${CHMOD} +x ${PREFIX}/${INSTIKIDIR}/instiki

.include <bsd.port.mk>
