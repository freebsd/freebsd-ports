#include "bridge.h"

SQLITE_EXTENSION_INIT3

//- routine that work with sqlite3_context; see: https://sqlite.org/c3ref/context.html
//-----------------------------

void* _sqlite3_aggregate_context(sqlite3_context *ctx, int n){ return sqlite3_aggregate_context(ctx, n); }
sqlite3* _sqlite3_context_db_handle(sqlite3_context *ctx){ return sqlite3_context_db_handle(ctx); }
void* _sqlite3_user_data(sqlite3_context *ctx){ return sqlite3_user_data(ctx); }
void* _sqlite3_get_auxdata(sqlite3_context *ctx, int n){ return sqlite3_get_auxdata(ctx, n); }
void  _sqlite3_set_auxdata(sqlite3_context *ctx, int n, void *val, void (*destructor)(void *)){ return sqlite3_set_auxdata(ctx, n, val, destructor); }

void _sqlite3_result_blob0(sqlite3_context *ctx, const void *val, int n, void (*destructor)(void *)){ sqlite3_result_blob(ctx, val, n, destructor); }
void _sqlite3_result_blob64(sqlite3_context *ctx, const void *val, sqlite3_uint64 n, void (*destructor)(void *)){ sqlite3_result_blob64(ctx, val, n, destructor); }
void _sqlite3_result_double(sqlite3_context *ctx, double val){ sqlite3_result_double(ctx, val); }
void _sqlite3_result_error(sqlite3_context *ctx, const char *msg, int n){ sqlite3_result_error(ctx, msg, n); }
void _sqlite3_result_error_code(sqlite3_context *ctx, int code){ sqlite3_result_error_code(ctx, code); }
void _sqlite3_result_error_nomem(sqlite3_context *ctx){ sqlite3_result_error_nomem(ctx); }
void _sqlite3_result_error_toobig(sqlite3_context *ctx){ sqlite3_result_error_toobig(ctx); }
void _sqlite3_result_int(sqlite3_context *ctx, int val){ sqlite3_result_int(ctx, val); }
void _sqlite3_result_int64(sqlite3_context *ctx, sqlite_int64 val){ sqlite3_result_int(ctx, val); }
void _sqlite3_result_null(sqlite3_context *ctx){ sqlite3_result_null(ctx); }
void _sqlite3_result_text0(sqlite3_context *ctx, const char *val, int n, void (*destructor)(void *)){ sqlite3_result_text(ctx, val, n, destructor); }
void _sqlite3_result_value(sqlite3_context *ctx, sqlite3_value *val){ sqlite3_result_value(ctx, val); }
void _sqlite3_result_pointer(sqlite3_context *ctx, void *val, const char *name, void (*destructor)(void *)){ sqlite3_result_pointer(ctx, val, name, destructor); }
void _sqlite3_result_zeroblob(sqlite3_context *ctx, int sz){ return sqlite3_result_zeroblob(ctx, sz); }
int  _sqlite3_result_zeroblob64(sqlite3_context *ctx, sqlite3_uint64 sz){ return sqlite3_result_zeroblob64(ctx, sz); }
void _sqlite3_result_subtype(sqlite3_context *ctx, unsigned int v){return sqlite3_result_subtype(ctx, v);}

// routines that work with sqlite_stmt; see: https://sqlite.org/c3ref/stmt.html
//-----------------------------

// constructor + destructor
int _sqlite3_prepare_v2(sqlite3 *db, const char *sql, int n, sqlite3_stmt **stmt, const char **tail){ return sqlite3_prepare_v2(db, sql, n, stmt, tail); }
int _sqlite3_finalize(sqlite3_stmt* stmt){ return sqlite3_finalize(stmt); }

// stepping / executing a prepared statement
int _sqlite3_step(sqlite3_stmt *stmt){ return sqlite3_step(stmt); }
int _sqlite3_reset(sqlite3_stmt *stmt){ return sqlite3_reset(stmt); }
int _sqlite3_clear_bindings(sqlite3_stmt *stmt){ return sqlite3_clear_bindings(stmt); }
int _sqlite3_data_count(sqlite3_stmt *stmt){ return sqlite3_data_count(stmt); }
int _sqlite3_column_count(sqlite3_stmt *stmt){ return sqlite3_column_count(stmt); }
sqlite3* _sqlite3_db_handle(sqlite3_stmt* stmt){ return sqlite3_db_handle(stmt); }

// binding values to prepared statement
int _sqlite3_bind_blob(sqlite3_stmt *stmt, int i, const void *val, int n, void (*destructor)(void *)){ return sqlite3_bind_blob(stmt, i, val, n, destructor); }
int _sqlite3_bind_double(sqlite3_stmt *stmt, int i, double val){ return sqlite3_bind_double(stmt, i, val); }
int _sqlite3_bind_int(sqlite3_stmt *stmt, int i, int val){ return sqlite3_bind_int(stmt, i, val); }
int _sqlite3_bind_int64(sqlite3_stmt *stmt, int i, sqlite_int64 val){ return sqlite3_bind_int64(stmt, i, val); }
int _sqlite3_bind_null(sqlite3_stmt *stmt, int i){ return sqlite3_bind_null(stmt, i); }
int _sqlite3_bind_text(sqlite3_stmt *stmt, int i, const char *val, int n, void (*destructor)(void *)){ return sqlite3_bind_text(stmt, i, val, n, destructor); }
int _sqlite3_bind_pointer(sqlite3_stmt *stmt, int i, void *val, const char *type, void (*destructor)(void *)){ return sqlite3_bind_pointer(stmt, i, val, type, destructor); }
int _sqlite3_bind_value(sqlite3_stmt *stmt, int i, const sqlite3_value *val){ return sqlite3_bind_value(stmt, i, val); }
int _sqlite3_bind_zeroblob(sqlite3_stmt *stmt, int i, int sz){ return sqlite3_bind_zeroblob(stmt, i, sz); }
int _sqlite3_bind_zeroblob64(sqlite3_stmt *stmt, int i, sqlite3_uint64 sz){ return sqlite3_bind_zeroblob64(stmt, i, sz); }

int _sqlite3_bind_parameter_count(sqlite3_stmt *stmt){ return sqlite3_bind_parameter_count(stmt); }
int _sqlite3_bind_parameter_index(sqlite3_stmt *stmt, const char *name){ return sqlite3_bind_parameter_index(stmt, name); }
const char* _sqlite3_bind_parameter_name(sqlite3_stmt *stmt, int n){ return sqlite3_bind_parameter_name(stmt, n); }

// reading result values from an sqlite3_stmt
const void* _sqlite3_column_blob(sqlite3_stmt* stmt, int i){ return sqlite3_column_blob(stmt, i); }
double _sqlite3_column_double(sqlite3_stmt* stmt, int i){ return sqlite3_column_double(stmt, i); }
int _sqlite3_column_int(sqlite3_stmt* stmt, int i){ return sqlite3_column_int(stmt, i); }
sqlite3_int64 _sqlite3_column_int64(sqlite3_stmt* stmt, int i){ return sqlite3_column_int64(stmt, i); }
const unsigned char* _sqlite3_column_text(sqlite3_stmt* stmt, int i){ return sqlite3_column_text(stmt, i); }
sqlite3_value* _sqlite3_column_value(sqlite3_stmt* stmt, int i){ return sqlite3_column_value(stmt, i); }
int _sqlite3_column_bytes(sqlite3_stmt* stmt, int i){ return sqlite3_column_bytes(stmt, i); }

// query sqlite3_stmt column information
const char* _sqlite3_column_name(sqlite3_stmt* stmt, int i){ return sqlite3_column_name(stmt, i); }
int _sqlite3_column_type(sqlite3_stmt* stmt, int i){ return sqlite3_column_type(stmt, i); }
const char* _sqlite3_column_database_name(sqlite3_stmt *stmt, int i){ return sqlite3_column_database_name(stmt, i); }
const char* _sqlite3_column_table_name(sqlite3_stmt *stmt, int i){ return sqlite3_column_table_name(stmt, i); }
const char* _sqlite3_column_origin_name(sqlite3_stmt *stmt, int i){ return sqlite3_column_origin_name(stmt, i); }

// meta-information about the statement itself
int _sqlite3_stmt_readonly(sqlite3_stmt* pStmt) { return sqlite3_stmt_readonly(pStmt); }

// routines to extract value from sqlite3_value type; see: https://sqlite.org/c3ref/value.html
//-----------------------------

const void* _sqlite3_value_blob(sqlite3_value *val){ return sqlite3_value_blob(val); }
double _sqlite3_value_double(sqlite3_value *val){ return sqlite3_value_double(val); }
int _sqlite3_value_int(sqlite3_value *val){ return sqlite3_value_int(val); }
sqlite_int64 _sqlite3_value_int64(sqlite3_value *val){ return sqlite3_value_int64(val); }
const unsigned char* _sqlite3_value_text(sqlite3_value *val){ return sqlite3_value_text(val); }
int _sqlite3_value_bytes(sqlite3_value *val){ return sqlite3_value_bytes(val); }
int _sqlite3_value_type(sqlite3_value *val){ return sqlite3_value_type(val); }
unsigned int _sqlite3_value_subtype(sqlite3_value *val){ return sqlite3_value_subtype(val); }
int _sqlite3_value_numeric_type(sqlite3_value *val){ return sqlite3_value_numeric_type(val); }
void* _sqlite3_value_pointer(sqlite3_value *val, const char *name){ return sqlite3_value_pointer(val, name); }
int _sqlite3_value_nochange(sqlite3_value *val){ return sqlite3_value_nochange(val); }

// routines to register application-defined sql functions
//-----------------------------

int _sqlite3_create_collation_v2(sqlite3 *db, const char *zName, int eTextRep, void *pUserData, int (*xCompare)(void *, int, const void *, int, const void *), void (*xDestroy)(void *)){ return sqlite3_create_collation_v2(db, zName, eTextRep, pUserData, xCompare, xDestroy); }
int _sqlite3_create_function_v2(sqlite3 *db, const char *zName, int nArgs, int eTextRep, void *pApp, void (*xFunc)(sqlite3_context *, int, sqlite3_value **), void (*xStep)(sqlite3_context *, int, sqlite3_value **), void (*xFinal)(sqlite3_context *), void (*xDestroy)(void *)){ return sqlite3_create_function_v2(db, zName, nArgs, eTextRep, pApp, xFunc, xStep, xFinal, xDestroy); }
int _sqlite3_create_window_function(sqlite3 *db, const char *zName, int nArgs, int eTextRep, void *pApp, void (*xStep)(sqlite3_context *, int, sqlite3_value **), void (*xFinal)(sqlite3_context *), void (*xValue)(sqlite3_context *), void (*xInverse)(sqlite3_context *, int, sqlite3_value **), void (*xDestroy)(void *)) { return sqlite3_create_window_function(db, zName, nArgs, eTextRep, pApp, xStep, xFinal, xValue, xInverse, xDestroy); }

// memory related operations
void* _sqlite3_malloc(int sz){ return sqlite3_malloc(sz); }
void* _sqlite3_realloc(void *p, int sz){ return sqlite3_realloc(p, sz); }
void  _sqlite3_free(void *p){ sqlite3_free(p); }

// error details handler
int _sqlite3_errcode(sqlite3 *db){ return sqlite3_errcode(db); }
const char *_sqlite3_errmsg(sqlite3 *db){ return sqlite3_errmsg(db); }

// auth+tracing
int _sqlite3_set_authorizer(sqlite3 *db, int (*xAuth)(void *, int, const char *, const char *, const char *, const char *), void *pUserData){ return sqlite3_set_authorizer(db, xAuth, pUserData); }
int _sqlite3_trace_v2(sqlite3 *db, unsigned int uMask, int (*xCallback)(unsigned int, void *, void *, void *), void *pUserData){ return sqlite3_trace_v2(db, uMask, xCallback, pUserData); };

// hooks
void* _sqlite3_commit_hook(sqlite3 *db, int (*xCallback)(void *), void *pUserData){ return sqlite3_commit_hook(db, xCallback, pUserData); }
void* _sqlite3_rollback_hook(sqlite3 *db, void (*xCallback)(void *), void *pUserData){ return sqlite3_rollback_hook(db, xCallback, pUserData); }
void* _sqlite3_update_hook(sqlite3 *db, void (*xCallback)(void *, int, const char *, const char *, sqlite_int64), void *pUserData){ return sqlite3_update_hook(db, xCallback, pUserData); }

// version number information
sqlite_int64 _sqlite3_last_insert_rowid(sqlite3 *db){ return sqlite3_last_insert_rowid(db); }
const char* _sqlite3_libversion(void){ return sqlite3_libversion(); }
int _sqlite3_libversion_number(void) { return sqlite3_libversion_number(); }

// Virtual table routines
int _sqlite3_create_module_v2(sqlite3 *db, const char *name, const sqlite3_module *module, void *pApp, void (*destructor)(void *)){ return sqlite3_create_module_v2(db, name, module, pApp, destructor); }
int _sqlite3_declare_vtab(sqlite3 *db, const char *sql) { return sqlite3_declare_vtab(db, sql); }

// miscellaneous routines
int _sqlite3_get_autocommit(sqlite3 *db){ return sqlite3_get_autocommit(db); }
int _sqlite3_enable_shared_cache(int enable){ return sqlite3_enable_shared_cache(enable); }
void _sqlite3_interrupt(sqlite3 *db){ sqlite3_interrupt(db); }
int _sqlite3_release_memory(int i){ return sqlite3_release_memory(i); }
int _sqlite3_threadsafe(void){ return sqlite3_threadsafe(); }
int _sqlite3_limit(sqlite3* db, int id, int val){ return sqlite3_limit(db, id, val); }

