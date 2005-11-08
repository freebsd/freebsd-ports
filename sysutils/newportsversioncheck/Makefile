# New ports collection makefile for:	newportsversioncheck
# Date created:				12 October 2005
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	newportsversioncheck
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Ports new version checker

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL_RUN=	yes
USE_SQLITE=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/newportsversioncheck/bin
.for f in apply_restrictions.pl check_data.pl check_find_new_versions.sh delete_dupes.pl filter_ports_alreadychecked.pl find_new_versions.pl find_new_versions.sh init_db.sh mail_maintainers.pl make_html.pl maketarball.sh manage_restriction.pl restart_database.pl README CHANGES
	${INSTALL_SCRIPT} ${WRKDIR}/newportsversioncheck/bin/${f} ${PREFIX}/newportsversioncheck/bin
.endfor

	${MKDIR} ${PREFIX}/newportsversioncheck/etc
.for f in email_footer.txt email_header.txt
	${INSTALL_DATA} ${WRKDIR}/newportsversioncheck/etc/${f} ${PREFIX}/newportsversioncheck/etc
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
