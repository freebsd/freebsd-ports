#include <sys/param.h>
#include <pwd.h>
#include <grp.h>
#include <nss.h>

extern enum nss_status _nss_ldap_getgrent_r(struct group *, char *, size_t,
    int *);
extern enum nss_status _nss_ldap_getgrnam_r(const char *, struct group *,
    char *, size_t, int *);
extern enum nss_status _nss_ldap_getgrgid_r(gid_t gid, struct group *, char *,
    size_t, int *);
extern enum nss_status _nss_ldap_setgrent(void);
extern enum nss_status _nss_ldap_endgrent(void);

extern enum nss_status _nss_ldap_getpwent_r(struct passwd *, char *, size_t,
    int *);
extern enum nss_status _nss_ldap_getpwnam_r(const char *, struct passwd *,
    char *, size_t, int *);
extern enum nss_status _nss_ldap_getpwuid_r(gid_t gid, struct passwd *, char *,
    size_t, int *);
extern enum nss_status _nss_ldap_setpwent(void);
extern enum nss_status _nss_ldap_endpwent(void);

NSS_METHOD_PROTOTYPE(__nss_compat_getgrnam_r);
NSS_METHOD_PROTOTYPE(__nss_compat_getgrgid_r);
NSS_METHOD_PROTOTYPE(__nss_compat_getgrent_r);
NSS_METHOD_PROTOTYPE(__nss_compat_setgrent);
NSS_METHOD_PROTOTYPE(__nss_compat_endgrent);

NSS_METHOD_PROTOTYPE(__nss_compat_getpwnam_r);
NSS_METHOD_PROTOTYPE(__nss_compat_getpwuid_r);
NSS_METHOD_PROTOTYPE(__nss_compat_getpwent_r);
NSS_METHOD_PROTOTYPE(__nss_compat_setpwent);
NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);

static ns_mtab methods[] = {
{ NSDB_GROUP, "getgrnam_r", __nss_compat_getgrnam_r, _nss_ldap_getgrnam_r },
{ NSDB_GROUP, "getgrgid_r", __nss_compat_getgrgid_r, _nss_ldap_getgrgid_r },
{ NSDB_GROUP, "getgrent_r", __nss_compat_getgrent_r, _nss_ldap_getgrent_r },
{ NSDB_GROUP, "endgrent",   __nss_compat_setgrent,   _nss_ldap_setgrent },
{ NSDB_GROUP, "setgrent",   __nss_compat_endgrent,   _nss_ldap_endgrent },

{ NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, _nss_ldap_getpwnam_r },
{ NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, _nss_ldap_getpwuid_r },
{ NSDB_PASSWD, "getpwent_r", __nss_compat_getpwent_r, _nss_ldap_getpwent_r },
{ NSDB_PASSWD, "endpwent",   __nss_compat_setpwent,   _nss_ldap_setpwent },
{ NSDB_PASSWD, "setpwent",   __nss_compat_endpwent,   _nss_ldap_endpwent },

{ NSDB_GROUP_COMPAT, "getgrnam_r", __nss_compat_getgrnam_r, _nss_ldap_getgrnam_r },
{ NSDB_GROUP_COMPAT, "getgrgid_r", __nss_compat_getgrgid_r, _nss_ldap_getgrgid_r },
{ NSDB_GROUP_COMPAT, "getgrent_r", __nss_compat_getgrent_r, _nss_ldap_getgrent_r },
{ NSDB_GROUP_COMPAT, "endgrent",   __nss_compat_setgrent,   _nss_ldap_setgrent },
{ NSDB_GROUP_COMPAT, "setgrent",   __nss_compat_endgrent,   _nss_ldap_endgrent },

{ NSDB_PASSWD_COMPAT, "getpwnam_r", __nss_compat_getpwnam_r, _nss_ldap_getpwnam_r },
{ NSDB_PASSWD_COMPAT, "getpwuid_r", __nss_compat_getpwuid_r, _nss_ldap_getpwuid_r },
{ NSDB_PASSWD_COMPAT, "getpwent_r", __nss_compat_getpwent_r, _nss_ldap_getpwent_r },
{ NSDB_PASSWD_COMPAT, "endpwent",   __nss_compat_setpwent,   _nss_ldap_setpwent },
{ NSDB_PASSWD_COMPAT, "setpwent",   __nss_compat_endpwent,   _nss_ldap_endpwent },

};


ns_mtab *
nss_module_register(const char *source, unsigned int *mtabsize,
    nss_module_unregister_fn *unreg)
{
	*mtabsize = sizeof(methods)/sizeof(methods[0]);
	*unreg = NULL;
	return (methods);
}
