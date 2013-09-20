# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
DISTVERSION=	1.2.3
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-${FREESWITCH_CONF_DIST}-devel
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch configuration files; ${FREESWITCH_CONF_DIST} variant

RUN_DEPENDS=    freeswitch:${PORTSDIR}/net/freeswitch-core-devel

FREESWITCH_CONF_DIST?=	vanilla

USE_BZIP2=	yes
NO_BUILD=	yes
SHAREOWN=	${PORTNAME}
SHAREGRP=	${SHAREOWN}

PLIST=	${MASTERDIR}/pkg-plist-${FREESWITCH_CONF_DIST}

WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/conf/${FREESWITCH_CONF_DIST}

# Do some checking and conflict on other conf dists
VALID_DISTS=	vanilla sbc curl insideout

.for d in ${FREESWITCH_CONF_DIST}
.  if ${VALID_DISTS:M$d}
CONFLICTS_INSTALL=	${VALID_DISTS:N$d:S/^/freeswitch-/:S/$/-devel-[0-9]*/}
.  else
IGNORE=	requires a valid conf distribution in FREESWITCH_CONF_DIST; use a slave port
.  endif
.endfor

CONF_EXTENSIONS=	xml ttml tpl conf types yaml FS0

NO_STAGE=	yes
post-patch:
	@cd ${WRKSRC} && for i in $$(${FIND} . -type f ${CONF_EXTENSIONS:C/.*/-name \*.& -o/} -false); \
		do [ -f $${i}.sample ] || ${MV} $$i $${i}.sample ; done

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${ETCDIR}/conf/
	${FIND} ${ETCDIR} -type d -exec chmod 770 '{}' \;
	for i in $$(cd ${WRKSRC} && ${FIND} * \
	  -type f -name '*.sample' | ${SED} 's|^|${ETCDIR_REL}/conf/|'); \
	    do	${ECHO_CMD} "@unexec cmp -s %D/$$i %D/$${i%.sample} && ${RM} %D/$${i%.sample} || ${TRUE}" >> ${TMPPLIST}; \
		${ECHO_CMD} "$$i" >> ${TMPPLIST} ; \
		${ECHO_CMD} "@exec [ -f %D/$${i%.sample} ] || \
			${CP} -p %D/%F %D/$${i%.sample}" >> ${TMPPLIST} ; \
		[ -f ${ETCDIR}/conf/$${i%.sample} ] || ${CP} -p ${PREFIX}/$$i ${PREFIX}/$${i%.sample} ; \
	done
	${TOUCH} ${ETCDIR}/conf/.${FREESWITCH_CONF_DIST}
	${ECHO_CMD} '${ETCDIR_REL}/conf/.${FREESWITCH_CONF_DIST}' >> ${TMPPLIST}
	for dir in $$(cd ${WRKSRC} && ${FIND} * -type d -not -path directory\* | ${SORT} -r) ; \
	    do	${ECHO_CMD} "@dirrm ${ETCDIR_REL}/conf/$$dir" >> ${TMPPLIST} ; \
	done


.include <bsd.port.mk>
