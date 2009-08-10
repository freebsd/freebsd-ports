# ex:ts=4 sw=4
#
# New ports collection makefile for:	foswiki infrastructure
# Date created:		15 June 2009
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
# Copied From Whom:	Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

#
# For more info, please go to http://wiki.FreeBSD.org/TWiki
#

PORTVERSION?=	0.0.${SVNREV}
.if ${PORTNAME} == foswiki
.if ${.TARGETS} == make-port
PNAME=		
.else
PNAME=		core
.endif
FWDIR?=		${WWWDIR}
.else
USE_BZIP2=	yes
PKGNAMEPREFIX?=	foswiki-
PNAME=		${PORTNAME}
FILESDIR?=	${.CURDIR}/../foswiki/files
BUILD_DEPENDS+=	foswiki>=0:${PORTSDIR}/www/foswiki
FWDIR?=		${WWWDIR}/${PNAME}
.endif

MASTER_SITES?=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
DIST_SUBDIR?=	foswiki
CATEGORIES?=	www
SVNURL?=	http://svn.foswiki.org/trunk/${PNAME}
NO_BUILD=	yes
WWWDIR?=	${PREFIX}/www/foswiki
PLIST_SUB+=	FWDIR=${FWDIR:S|^${PREFIX}/||}
SUB_LIST+=	FWDIR=${FWDIR} FIND=${FIND} CHMOD=${CHMOD} CHOWN=${CHOWN} \
		TOUCH=${TOUCH} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		CONFDIR=${CONFDIR}
SUB_FILES+=	pkg-install
MAINTAINER?=	glarkin@FreeBSD.org
RUN_DEPENDS+=	${FWDEP:C/([^=<>]*)([=<>]*)(.*)/foswiki-\1\20.0.\3:${PORTSDIR}\/www\/foswiki-\1/}

make-dist:
	${INSTALL} -d ${WRKDIR}/
	#cd ${WRKDIR}/ && svn export -r ${SVNREV} ${SVNURL} && \
	#	${MV} ${PNAME} ${DISTNAME} && \
	#	${FIND} . -type d -empty | ${SED} -e 's|$$|/.keep_me|' | \
	#	${XARGS} ${TOUCH} && \
	#	${TAR} cjvf ${DISTNAME}.tar.bz2 ${DISTNAME}
	cd ${WRKDIR}/ && svn export -r ${SVNREV} ${SVNURL} && \
		${MV} ${PNAME} ${DISTNAME} && \
		${FIND} . -type d -empty | ${SED} -e 's|$$|/.keep_me|' | \
		${XARGS} ${TOUCH}

create-plist:	extract
	@${FIND} -s ${WRKSRC} -not -type d |\
		${SED} -e 's|^${WRKSRC}|%%FWDIR%%|' > ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d -not -name ${DISTNAME} | \
		${SED} -e "s,^${WRKSRC},@dirrm %%FWDIR%%," >> ${PLIST}
	@${ECHO_CMD} '@dirrm %%FWDIR%%' >> ${PLIST}

do-install:
	@${INSTALL} -d ${FWDIR}/
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${FWDIR}/
.if ${PORTNAME} == foswiki
	@${INSTALL_DATA} ${WRKDIR}/LocalSite.cfg ${WWWDIR}/lib
.endif
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

make-fwdep: extract
	@echo "FWDEP=`grep -v ^# ${WRKSRC}/lib/*[wW]iki/*/${PORTNAME}/DEPENDENCIES |\
		grep -v ',cpan,'|cut -f1-2 -d, | ${SED} -e 's|.*::||;s|,||g' |\
		tr '\n' ' ' | sed 's| $$||'`"
	@echo "RUN_DEPENDS=`grep -v ^# ${WRKSRC}/lib/*[wW]iki/*/${PORTNAME}/DEPENDENCIES |\
		grep ',cpan,' | cut -f1-2 -d, | ${SED} -e 's|::|-|' | while read a; do\
			n=p5-$${a%%,*}; v=$${a##*,}; \
			o=\`echo ${PORTSDIR}/*/$$n\`; : $${o:=${PORTSDIR}/X/$$n}; \
			echo $$n$$v:'$${PORTSDIR}'$${o##${PORTSDIR}}; done`"

make-port:
	${INSTALL} -d ${_DISTDIR}
	for n in ${name} ${names}; do\
	cd ../ &&\
	nnam="$${n%%:*}" &&\
	nver="$${n##$$nnam}" &&\
	nver="$${nver##:}" &&\
	if [ -z "$$nver" ]; then \
	nver=`svn log -q -l 1 ${SVNURL}$$nnam | grep -v '^--------' | awk '{ print $$1 }' | cut -c2-`; fi &&\
	pnam="foswiki-$$nnam" &&\
	if [ -d $$pnam ]; then continue; fi &&\
	mkdir $$pnam/ && cd $$pnam/ &&\
	echo "# New ports collection makefile for:	$$pnam" > Makefile &&\
	date '+# Date created:%t%t%e %B %Y' >> Makefile &&\
	echo '#' >> Makefile &&\
	echo '# $$''FreeBSD$$' >> Makefile &&\
	echo '#' >> Makefile &&\
	echo >> Makefile &&\
	echo "PORTNAME=	$$nnam" >> Makefile &&\
	echo "MAINTAINER=	${MAINTAINER}" >> Makefile &&\
	echo >> Makefile &&\
	echo "SVNREV=		$$nver" >> Makefile &&\
	echo >> Makefile &&\
	echo 'COMMENT=	' >> Makefile &&\
	echo >> Makefile &&\
	echo 'BUILD_DEPENDS=	foswiki>=0:${PORTSDIR}/www/foswiki' >> Makefile &&\
	echo >> Makefile &&\
	echo '.include "$${.CURDIR}/../foswiki/bsd.foswiki.mk"' >> Makefile &&\
	echo '.include <bsd.port.mk>' >> Makefile &&\
	wrksrc=`make -V WRKSRC` &&\
	make make-dist &&\
	: "mv `make -V WRKDIR`/*bz2 ${_DISTDIR}/" &&\
	: "make makesum create-plist" &&\
	page1="$$wrksrc/data/TWiki/$$nnam.txt" &&\
	page2="$$wrksrc/data/System/$$nnam.txt" &&\
	if [ -e $$page1 ]; then \
	page=$$page1; elif [ -e $$page2 ]; then \
	page=$$page2; else \
	echo "Could not locate $$page1 or $$page2"; exit; fi &&\
	grep -m1 'Set SHORTDESC' $$page |\
		sed -e 's|.*N = ||;s|<nop>||g;s|! |. |g;s|!||g;s|=||g' |\
		fmt -w 70 > pkg-descr &&\
	echo >> pkg-descr &&\
	grep -m1 Author $$page|grep '^|' |cut -f3 -d'|' |\
		sed -E 's|.+[wW]iki:Main[./]||g;s|^|Author: |;s|  | |g;s| $$||;\
		s|([a-z]) |\1, |;s|([a-z])([A-Z])|\1 \2|g' >> pkg-descr &&\
	echo "WWW:	http://www.foswiki.org/Support/$$nnam" >> pkg-descr;\
	done
