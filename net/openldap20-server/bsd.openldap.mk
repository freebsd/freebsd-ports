#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# USE_OPENLDAP			- Says that the port uses the OpenLDAP libraries
#				- Implies WANT_OPENLDAP_VER?=21.
# WANT_OPENLDAP_VER		- legal values are: 12, 20, 21 and 22
#				- If set to an unknown value, the port is marked BROKEN.
##

######################################################################

######################################################################
# OpenLDAP

.if defined(USE_OPENLDAP_VER)
USE_OPENLDAP?=		yes
WANT_OPENLDAP_VER=	${USE_OPENLDAP_VER}
.endif

.if defined(USE_OPENLDAP)
WANT_OPENLDAP_VER?=	21
.if ${WANT_OPENLDAP_VER} == 12
LIB_DEPENDS+=		ldap.1:${PORTSDIR}/net/openldap12
.elif ${WANT_OPENLDAP_VER} == 20 || ${WANT_OPENLDAP_VER} == 21 || \
			${WANT_OPENLDAP_VER} == 22
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client
.else
BROKEN=			"unknown OpenLDAP version: ${WANT_OPENLDAP_VER}"
.endif
.endif

# END OpenLDAP
