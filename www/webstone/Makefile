# New ports collection makefile for:   webstone
# Version required:    2.0
# Date created:        25 March 1997
# Whom:                Soren Dossing <sauber@netcom.com>
#
# $Id$
#

DISTNAME=      WebStone-2.0
PKGNAME=       webstone-2.0.1
CATEGORIES=    www benchmarks
MASTER_SITES=  http://www.sgi.com/Products/WebFORCE/WebStone/

MAINTAINER=    sauber@netcom.com

GNU_CONFIGURE= yes
WRKSRC=        ${WRKDIR}/WebStone/src
ALL_TARGET=    install
NO_INSTALL_MANPAGES=yes

post-extract:
	( cd ${WRKSRC}; make clobber )

do-install:
	@${MKDIR} ${PREFIX}/webstone/bin
	@${MKDIR} ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${PREFIX}/webstone/bin
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${PREFIX}/webstone
.for file in webclient webmaster genrand
	strip ${PREFIX}/webstone/bin/${file}
.endfor

post-install:
	@echo ""
	@echo "Before running webstone make sure that the non-root user"
	@echo "who runs webstone has rexec access to the webclients and"
	@echo "the web server. This user must also have write access to"
	@echo "/usr/local/webstone on webmaster and write access in the"
	@echo "the web data directory on the web server. Be aware of"
	@echo "security risks!"
	@echo ""
	@echo "To run configure webstones, run it, and see the results:"
	@echo ""
	@echo "    cd /usr/local/webstone"
	@echo "    ${EDITOR} conf/testbed"
	@echo "    ./webstone -genfiles"
	@echo "    ./webstone"
	@echo "    ./webstone -results"
	@echo ""

.include <bsd.port.mk>
